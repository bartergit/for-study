import numpy as np
from lab1_1 import draw_line, define_orientation
from lab1_2 import is_intersect
from lab7_dynamic_convex_hull import append_point as append_point_to_hull
import matplotlib.pyplot as plt
import copy
import random
from lab1_3 import draw_figure


class Point():
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.bound_points = []

    def bind(self, point):
        if point not in self.bound_points:
            point.bound_points.append(self)
            self.bound_points.append(point)

    def unbind(self, point):
        point.bound_points.remove(self)
        self.bound_points.remove(point)

    def __eq__(self, other):
        try:
            return self.x == other.x and self.y == other.y
        except:
            return False

    def __repr__(self):
        return f"Point [{str(self.x)}, {str(self.y)}]"

    def __hash__(self):
        return hash((self.x, self.y))

    def __getitem__(self, ind):
        if ind == 0:
            return self.x
        if ind == 1:
            return self.y

    def __setitem__(self, ind, value):
        if ind == 0:
            self.x = value
        if ind == 1:
            self.y = value

    def distance(self, point):
        return ((self.x - point.x) ** 2 + (self.y - point.y) ** 2) ** (1 / 2)

    def __sub__(self, other):
        return Point(self.x - other.x, self.y - other.y)


def recursive_draw(point):
    bounded_points_copy = copy.copy(point.bound_points)
    while len(point.bound_points):
        draw_line(point.bound_points[0], point)
        point.bound_points[0].unbind(point)
    for point in bounded_points_copy:
        recursive_draw(point)


def draw_graph(original_points):
    points = copy.deepcopy(original_points)
    recursive_draw(points[0])
    # draw_line()


def define_circle(p1, p2, p3):
    # Returns the center and radius of the circle passing the given 3 points.
    # In case the 3 points form a line, returns (None, infinity).
    temp = p2[0] * p2[0] + p2[1] * p2[1]
    bc = (p1[0] * p1[0] + p1[1] * p1[1] - temp) / 2
    cd = (temp - p3[0] * p3[0] - p3[1] * p3[1]) / 2
    det = (p1[0] - p2[0]) * (p2[1] - p3[1]) - (p2[0] - p3[0]) * (p1[1] - p2[1])
    if abs(det) < 1.0e-6:
        return (None, np.inf)
    # Center of circle
    cx = (bc * (p2[1] - p3[1]) - cd * (p1[1] - p2[1])) / det
    cy = ((p1[0] - p2[0]) * cd - (p2[0] - p3[0]) * bc) / det
    radius = np.sqrt((cx - p1[0]) ** 2 + (cy - p1[1]) ** 2)
    return (Point(cx, cy), radius)


def check_condition(point1, point2, vertex1, vertex2):
    center1, radius1 = define_circle(point1, point2, vertex1)
    center2, radius2 = define_circle(point1, point2, vertex2)
    return center1.distance(vertex2) >= radius1 and center2.distance(vertex1) >= radius2


def find_visible_points(convex_hall, point_to_append):
    #найти угол между вектором нормали и вектором проекции. Если он тупой то ребро видимо
    sides = []
    for point in convex_hall:
        counter = 0
        for i in range(len(convex_hall)):
            if is_intersect(point_to_append, point, convex_hall[i], convex_hall[(i + 1) % len(convex_hall)]):
                counter += 1
        if counter == 2:
            sides.append(point)
        else:
            break
    stop_point = point
    for point in reversed(convex_hall):
        if point == stop_point:
            break
        counter = 0
        for i in range(len(convex_hall)):
            if is_intersect(point_to_append, point, convex_hall[i], convex_hall[(i + 1) % len(convex_hall)]):
                counter += 1
        if counter == 2:
            sides.append(point)
        else:
            break
    for i in range(len(sides)):
        orientation_set = set()
        for j in range(len(sides) - 1):
            orientation_set.add(
                define_orientation(point_to_append, sides[(j + i) % len(sides)], sides[(j + i + 1) % len(sides)]))
        if len(orientation_set) == 1:
            return sides[i:] + sides[:i]


def find_common_bound_points(point1, point2):
    common_points = tuple(frozenset(point1.bound_points).intersection(frozenset(point2.bound_points)))
    return common_points
    if len(common_points) == 0:
        print("zero common points")
        return []
    if len(common_points) == 1:
        return common_points
    if define_orientation(point1, point2, common_points[0]) == "left":
        return common_points
    else:
        return (common_points[1], common_points[0])


def recursive_change(point1, point2):
    common_points = find_common_bound_points(point1, point2)
    common_points_left = []
    common_points_right = []
    for common_point in common_points:
        if define_orientation(point1, point2, common_point) == "left":
            common_points_left.append(common_point)
        else:
            common_points_right.append(common_point)
        for point_right in common_points_right:
            for point_left in common_points_left:
                cond = check_condition(point1, point2, point_right, point_left)
                if not cond:
                    print("unbound {} --- {}".format(point1, point2))
                    print(f"bound {point_right} {point_left}")
                    try:
                        point1.unbind(point2)
                        point_right.bind(point_left)
                        recursive_change(point1, point_right)
                        recursive_change(point2, point_right)
                        recursive_change(point1, point_left)
                        recursive_change(point2, point_left)
                    except ValueError as ex:
                        print(f"Handled exception. {ex}")


def add_point(convex_hall, point_to_add):
    visible_points = find_visible_points(convex_hall, point_to_add)
    point_to_add.bind(visible_points[0])
    for ind in range(len(visible_points) - 1):
        point_to_add.bind(visible_points[ind + 1])
        recursive_change(visible_points[ind], visible_points[ind + 1])
    return append_point_to_hull(convex_hall, point_to_add)


def create_triangulation(original_points):
    points = copy.deepcopy(original_points)
    points = [i for n, i in enumerate(points) if i not in points[:n]]
    points.sort(key=lambda point: (point.y, point.x))
    points[0].bind(points[1])
    points[1].bind(points[2])
    points[2].bind(points[0])
    convex_hall = points[:3]
    for i in range(3, len(points)):
        print(f"{i}.")
        convex_hall = add_point(convex_hall, points[i])
    return points


if __name__ == "__main__":
    fig, ax = plt.subplots()
    points1 = [Point(0, 8.5), Point(8.2, 0), Point(8, 4), Point(14, 4), Point(19, 5.5), Point(3, 11), Point(7, 12),
               Point(12, 11.5), Point(17, 9), Point(19, 5.5)]
    coords = [(35, 425), (123, 365), (240, 192), (480, 67), (512, 212), (671, 161), (897, 431), (800, 383), (674, 377),
              (553, 445), (454, 542), (374, 452), (266, 394), (344, 374)]
    points2 = [Point(coord[0], coord[1]) for coord in coords]

    draw_graph(create_triangulation(points1))
    for point in points1:
        plt.plot(point.x, point.y, 'ro')
    plt.show()
    draw_graph(create_triangulation(points2))
    for point in points2:
        plt.plot(point.x, point.y, 'ro')
    plt.show()
