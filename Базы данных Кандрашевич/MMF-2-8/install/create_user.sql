DEFINE USER_NAME = &&1
DEFINE PASSWORD =  'oracle'

CREATE USER &USER_NAME identified by &PASSWORD;
PROMPT 'USER &&USER_NAME WAS CREATED'
