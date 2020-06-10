DEFINE USER_NAME = &&1

GRANT CREATE PROCEDURE TO &&USER_NAME;
GRANT CREATE SEQUENCE TO &&USER_NAME;
GRANT CREATE TABLE TO &&USER_NAME;
GRANT CREATE TYPE TO &&USER_NAME;
GRANT CREATE TRIGGER TO &&USER_NAME;
GRANT CREATE SYNONYM TO &&USER_NAME;
GRANT CREATE SESSION TO &&USER_NAME;
GRANT CREATE ANY DIRECTORY TO &&USER_NAME;
GRANT CREATE VIEW TO &&USER_NAME;
ALTER USER &&USER_NAME QUOTA UNLIMITED ON &&USER_NAME._DATA;
ALTER USER &&USER_NAME QUOTA UNLIMITED ON &&USER_NAME._IDX;
ALTER USER &&USER_NAME DEFAULT TABLESPACE &&USER_NAME._DATA TEMPORARY TABLESPACE "TEMP" ACCOUNT UNLOCK;