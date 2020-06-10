connect MMF_2_8/oracle 


CREATE TABLE DATA_TABLE (
    Championship INTEGER,
    League VARCHAR2(300),
    Founded_Team_1 INTEGER,
    Trainer_Team_1 VARCHAR2(300),
    Founded_Team_2 INTEGER,
    Trainer_Team_2 VARCHAR2(300),
    Team_1 VARCHAR2(300),
    Team_2 VARCHAR2(300),
    Event VARCHAR2(300),
    Player_Last_Name VARCHAR2(300),
    Player_Team VARCHAR2(300),
    Position VARCHAR2(300),
    Event_Time INTEGER,
    Event_Date DATE,
    Location VARCHAR2(300),
    Venue VARCHAR2(300),
    Capacity INTEGER,
    Avg_price INTEGER,
    tickets_sold INTEGER
)
TABLESPACE MMF_2_8_DATA;

alter session set nls_date_format = 'dd-mm-yyyy';

-- alter session set nls_language = RUSSIAN;

INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1996,'?�𣎎 ?��𡀣�',1964,'?���� ?��������','????','?����','Goal','?󨠊��','????','?���������',12,'03-05-2020','Borisov','?���-?𽭠',13121,15,6580);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1996,'?�𣎎 ?��𡀣�',1964,'?���� ?��������','????','?����','Goal','?�񽀣�','????','?�����򭣌',17,'03-05-2020','Borisov','?���-?𽭠',13121,15,6580);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1996,'?�𣎎 ?��𡀣�',1964,'?���� ?��������','????','?����','Goal','?�������','????','?�����򭣌',70,'03-05-2020','Borisov','?���-?𽭠',13121,15,6580);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1996,'?�𣎎 ?��𡀣�',1964,'?���� ?��������','????','?����','Goal','?������','?����','?�����򭣌',31,'03-05-2020','Borisov','?���-?𽭠',13121,15,6580);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1996,'?�𣎎 ?��𡀣�',1964,'?���� ?��������','????','?����','Yellow card','?󨠊��','????','?���������',22,'03-05-2020','Borisov','?���-?𽭠',13121,15,6580);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1996,'?�𣎎 ?��𡀣�',1964,'?���� ?��������','????','?����','Yellow card','?������','?����','?�����򭣌',23,'03-05-2020','Borisov','?���-?𽭠',13121,15,6580);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1996,'?�𣎎 ?��𡀣�',1964,'?���� ?��������','????','?����','Yellow card','?�����','?����','?���������',64,'03-05-2020','Borisov','?���-?𽭠',13121,15,6580);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1996,'?�𣎎 ?��𡀣�',1964,'?���� ?��������','????','?����','Yellow card','?����','?����','?���򭣌',72,'03-05-2020','Borisov','?���-?𽭠',13121,15,6580);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?���� ?��������',2016,'?���񠭪� ?�����','?����','?�� ?���','Goal','?������','?����','?�����򭣌',68,'09-05-2020','Grodno','??? ?����',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?���� ?��������',2016,'?���񠭪� ?�����','?����','?�� ?���','Goal','?������','?����','?�����򭣌',91,'09-05-2020','Grodno','??? ?����',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?���� ?��������',2016,'?���񠭪� ?�����','?����','?�� ?���','Goal','?�����','?�� ?���','?�����򭣌',4,'09-05-2020','Grodno','??? ?����',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?���� ?��������',2016,'?���񠭪� ?�����','?����','?�� ?���','Goal','?�����','?�� ?���','?�����򭣌',15,'09-05-2020','Grodno','??? ?����',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?���� ?��������',2016,'?���񠭪� ?�����','?����','?�� ?���','Goal','?�����','?�� ?���','?�����򭣌',55,'09-05-2020','Grodno','??? ?����',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?���� ?��������',2016,'?���񠭪� ?�����','?����','?�� ?���','Goal','?��𡭣�','?�� ?���','?�����򭣌',90,'09-05-2020','Grodno','??? ?����',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?���� ?��������',2016,'?���񠭪� ?�����','?����','?�� ?���','Yellow card','?����','?����','?���򭣌',68,'09-05-2020','Grodno','??? ?����',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?���� ?��������',2016,'?���񠭪� ?�����','?����','?�� ?���','Yellow card','?�������','?����','?�����򭣌',87,'09-05-2020','Grodno','??? ?����',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?���� ?��������',2016,'?���񠭪� ?�����','?����','?�� ?���','Yellow card','?�������','?�� ?���','?���򭣌',35,'09-05-2020','Grodno','??? ?����',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?���� ?��������',2016,'?���񠭪� ?�����','?����','?�� ?���','Yellow card','?�����','?�� ?���','?�����򭣌',51,'09-05-2020','Grodno','??? ?����',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?���� ?��������',2016,'?���񠭪� ?�����','?����','?�� ?���','Yellow card','?�����','?�� ?���','?�����򭣌',86,'09-05-2020','Grodno','??? ?����',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?���� ?��������',2016,'?���񠭪� ?�����','?����','?�� ?���','Yellow card','?��𡭣�','?�� ?���','?�����򭣌',81,'09-05-2020','Grodno','??? ?����',8479,16,5460);
INSERT INTO DATA_TABLE(Championship,League,Founded_Team_1,Trainer_Team_1,Founded_Team_2,Trainer_Team_2,Team_1,Team_2,Event,Player_Last_Name,Player_Team,Position,Event_Time,Event_Date,Location,Venue,Capacity,Avg_price,tickets_sold) VALUES(2020,'Belarusian Premier League',1964,'?���� ?��������',2016,'?���񠭪� ?�����','?����','?�� ?���','Red card','?�����','?�� ?���','?�����򭣌',82,'09-05-2020','Grodno','??? ?����',8479,16,5460);