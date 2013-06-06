-- check
-- pk
-- uq
-- fk
-- nullable
CREATE TABLE ORGANIZATIONS_TYPES (
    TYPE VARCHAR2(30),
    CONSTRAINT ORGANIZATIONS_TYPES_PK PRIMARY KEY (TYPE)
);
CREATE TABLE ORGANIZATIONS (
    ID NUMBER(6,0) NOT NULL,
    TITLE VARCHAR2(50) NOT NULL,
    CONTACT_PERSON_ID NUMBER(6,0),
    ORGANIZATION_TYPE VARCHAR2(30),
    CONSTRAINT ORGANIZATIONS_PK PRIMARY KEY (ID),
    CONSTRAINT ORGANIZATIONS_UQ_TITLE UNIQUE (TITLE)
);
CREATE TABLE PERSONS (
    ID NUMBER(6,0),
    FIRSTNAME VARCHAR2(50) NOT NULL,
    LASTNAME VARCHAR2(50) NOT NULL,
    EMAIL VARCHAR2(50) NOT NULL,
    PHONE VARCHAR2(20),
    IS_ACCOMMODATION_REQUIRED NUMBER(1,0),
    IS_ASSISTANCE_REQUIRED NUMBER(1,0),
    ORGANIZATION_ID NUMBER(6,0),

);
CREATE TABLE CARS (
    LICENCE_PLATE VARCHAR2(6) NOT NULL,
    MANUFACTURER VARCHAR2(20),
    MODEL VARCHAR2(20),
    YEAR DATE,
    IS_AVAILABLE NUMBER(1,0)
);
CREATE TABLE LOCATIONS (
    ID NUMBER(6,0) NOT NULL,
    ORGANIZATION NUMBER(5,0) NOT NULL,
    ADDRESS VARCHAR2(100),
    HAS_PARKING NUMBER(1,0)
);
CREATE TABLE LOCATIONS_AUDITORIUMS(
    ID NUMBER(6,0) NOT NULL,
    LOCATION_ID NUMBER(6,0) NOT NULL,
    AUDITORIUM VARCHAR2(30),
    PLACES NUMBER(3,0),
    HAS_WORKSTATION NUMBER(1,0)
);
CREATE TABLE LOCATIONS_HOTELS(
    ID NUMBER(6,0) NOT NULL,
    LOCATION_ID NUMBER(6,0) NOT NULL,
    HOTEL_STARS NUMBER(1,0),
    PRICE NUMBER(3,2),
    ROOMS NUMBER(3,0)
);
CREATE TABLE CONFERENCES(
    CODE VARCHAR2(10),
    TITLE VARCHAR2(50),
    START_DATE DATE,
    END_DATE DATE
);
CREATE TABLE SECTIONS(
    ID NUMBER(6,0) NOT NULL,
    CONFERENCE_CODE VARCHAR2(10) NOT NULL,
    TITLE VARCHAR2(50) NOT NULL
);
CREATE TABLE REFERATS(
    ID NUMBER(6,0) NOT NULL,
    SECTION_ID NUMBER(6,0) NOT NULL,
    TITLE VARCHAR2(50) NOT NULL,
    DESCRIPTION VARCHAR2(2000)
);
CREATE TABLE LECTIONS(
    REFERAT_ID NUMBER(6,0) NOT NULL,
    IS_WORKSHOP NUMBER(1,0),
    LOCATIONS_AUDITORIUM_ID NUMBER(6,0) NOT NULL,
    START_DATETIME DATE NOT NULL,
    END_DATETIME DATE,
    IS_FREE NUMBER(1,0) DEFAULT 1
);
CREATE TABLE REFERAT_PARTS(
    PART VARCHAR2(10) NOT NULL,
    WEIGHT NUMBER(2,0)
);
CREATE TABLE REFERAT_PARTS_SUBMITTED(
    REFERAT_ID NUMBER(6,0) NOT NULL,
    REFERAT_PART VARCHAR2(10) NOT NULL
);
CREATE TABLE RATINGS(
    RATING VARCHAR2(10)
);
CREATE TABLE PARTICIPANTS(
    PERSON_ID NUMBER(6,0),
    LECTURE_ID NUMBER(6,0),
    RATED VARCHAR2(10),
    CHECKED_IN NUMBER(1,0)
);
CREATE TABLE LECTURERS(
    PERSON_ID NUMBER(6,0) NOT NULL,
    REFERAT_ID NUMBER(6,0) NOT NULL
);
CREATE TABLE HELPTEAM(
    PERSON_ID NUMBER(6,0) NOT NULL,
    IS_FULL_TYME NUMBER(1,0),
    HAS_DRIVING_LICENCE NUMBER(1,0)
);