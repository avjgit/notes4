-- uq
-- fk
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
    CONSTRAINT ORGANIZATIONS_UQ UNIQUE (TITLE)
  -- CONSTRAINT fk_column
  --   FOREIGN KEY (column1, column2, ... column_n)
  --   REFERENCES parent_table (column1, column2, ... column_n)
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
    CONSTRAINT PERSONS_PK PRIMARY KEY (ID),
    CONSTRAINT PERSONS_UQ UNIQUE (EMAIL)
);
CREATE TABLE CARS (
    LICENCE_PLATE VARCHAR2(6) NOT NULL,
    MANUFACTURER VARCHAR2(20),
    MODEL VARCHAR2(20),
    YEAR DATE,
    IS_AVAILABLE NUMBER(1,0),
    CONSTRAINT CARS_PK PRIMARY KEY (LICENCE_PLATE)
);
CREATE TABLE LOCATIONS (
    ID NUMBER(6,0) NOT NULL,
    ORGANIZATION_ID NUMBER(5,0) NOT NULL,
    ADDRESS VARCHAR2(100) NOT NULL,
    HAS_PARKING NUMBER(1,0),
    CONSTRAINT LOCATIONS_PK PRIMARY KEY (ID),
    CONSTRAINT LOCATIONS_UQ UNIQUE (ORGANIZATION_ID, ADDRESS)
);
CREATE TABLE AUDITORIUMS(
    ID NUMBER(6,0) NOT NULL,
    LOCATION_ID NUMBER(6,0) NOT NULL,
    AUDITORIUM VARCHAR2(30) NOT NULL,
    PLACES NUMBER(3,0),
    HAS_WORKSTATION NUMBER(1,0),
    CONSTRAINT AUDITORIUMS_PK PRIMARY KEY (ID),
    CONSTRAINT AUDITORIUMS_UQ UNIQUE (AUDITORIUM)
);
CREATE TABLE HOTELS(
    ID NUMBER(6,0) NOT NULL,
    LOCATION_ID NUMBER(6,0) NOT NULL,
    HOTEL_STARS NUMBER(1,0),
    PRICE NUMBER(3,2),
    ROOMS NUMBER(3,0),
    CONSTRAINT HOTELS_PK PRIMARY KEY (ID),
    CONSTRAINT HOTELS_UQ UNIQUE (LOCATION_ID)
);
CREATE TABLE CONFERENCES(
    CODE VARCHAR2(10) NOT NULL,
    TITLE VARCHAR2(50) NOT NULL,
    START_DATE DATE,
    END_DATE DATE,
    CONSTRAINT CONFERENCES_PK PRIMARY KEY (CODE)
);
CREATE TABLE SECTIONS(
    ID NUMBER(6,0) NOT NULL,
    TITLE VARCHAR2(50) NOT NULL,
    CONSTRAINT SECTIONS_PK PRIMARY KEY (ID)
);
CREATE TABLE REFERATS(
    ID NUMBER(6,0) NOT NULL,
    SECTION_ID NUMBER(6,0) NOT NULL,
    TITLE VARCHAR2(50) NOT NULL,
    DESCRIPTION VARCHAR2(2000),
    CONSTRAINT REFERATS_PK PRIMARY KEY (ID)
);
CREATE TABLE LECTIONS(
    ID NUMBER(6,0) NOT NULL,
    LECTURER_ID NUMBER(6,0) NOT NULL,
    IS_WORKSHOP NUMBER(1,0),
    LOCATIONS_AUDITORIUM_ID NUMBER(6,0) NOT NULL,
    START_DATETIME DATE NOT NULL,
    END_DATETIME DATE,
    IS_FREE NUMBER(1,0) DEFAULT 1,
    CONSTRAINT LECTIONS_PK PRIMARY KEY (ID),
    CONSTRAINT LECTIONS_UQ UNIQUE (LECTURER_ID, START_DATETIME)
);
CREATE TABLE REFERAT_PARTS(
    PART VARCHAR2(10) NOT NULL,
    WEIGHT NUMBER(2,0),
    CONSTRAINT REFERAT_PARTS_PK PRIMARY KEY (PART)
);
CREATE TABLE REFERAT_PARTS_SUBMITTED(
    REFERAT_ID NUMBER(6,0) NOT NULL,
    REFERAT_PART VARCHAR2(10) NOT NULL,
    DATE_SUBMITTED DATE,
    CONSTRAINT REFERAT_PARTS_SUBMITTED_PK PRIMARY KEY (REFERAT_ID,REFERAT_PART)
);
CREATE TABLE RATINGS(
    RATING VARCHAR2(10) NOT NULL,
    CONSTRAINT RATINGS_PK PRIMARY KEY (RATING)
);
CREATE TABLE PARTICIPANTS(
    PERSON_ID NUMBER(6,0) NOT NULL,
    LECTURE_ID NUMBER(6,0) NOT NULL,
    RATED VARCHAR2(10),
    CHECKED_IN NUMBER(1,0),
    CONSTRAINT PARTICIPANTS_PK PRIMARY KEY (PERSON_ID, LECTURE_ID)
);
CREATE TABLE LECTURERS(
    ID NUMBER(6,0) NOT NULL,
    PERSON_ID NUMBER(6,0) NOT NULL,
    REFERAT_ID NUMBER(6,0) NOT NULL,
    CONSTRAINT LECTURERS_PK PRIMARY KEY (ID),
    CONSTRAINT LECTURERS_UQ UNIQUE (PERSON_ID, REFERAT_ID)
);
CREATE TABLE HELPTEAM(
    PERSON_ID NUMBER(6,0) NOT NULL,
    IS_FULL_TYME NUMBER(1,0),
    HAS_DRIVING_LICENCE NUMBER(1,0),
    CONSTRAINT HELPTEAM_PK PRIMARY KEY (PERSON_ID)
);