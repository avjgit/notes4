select * from all_tables where owner = 'AJ05044';
-------------------------------------------ORGANIZATIONS_TYPES 	
--TYPE	VARCHAR2(30 BYTE)	No
delete from organizations_types;
select * from ORGANIZATIONS_TYPES;
insert into organizations_types values('BUSINESS');
insert into organizations_types values('ACADEMIC');
insert into organizations_types values('GOVERNMENT');
-------------------------------------------ORGANIZATIONS 
--ID	NUMBER(6,0)	No
--TITLE	VARCHAR2(50 BYTE)	No
--CONTACT_PERSON_ID	NUMBER(6,0)	Yes
--ORGANIZATION_TYPE	VARCHAR2(30 BYTE)	Yes

select * from all_constraints where owner = 'AJ05044';

select table_name, constraint_name, status, owner
from all_constraints
where r_owner = 'AJ05044'
and constraint_type = 'R'
and r_constraint_name in
 (
   select constraint_name from all_constraints
   where constraint_type in ('P', 'U')
   and table_name = 'ORGANIZATIONS_TYPES'
   and owner = 'AJ05044'
 )
order by table_name, constraint_name;
 
SELECT   uc.constraint_name||CHR(10)
||      '('||ucc1.TABLE_NAME||'.'||ucc1.column_name||')' constraint_source
,       'REFERENCES'||CHR(10)
||      '('||ucc2.TABLE_NAME||'.'||ucc2.column_name||')' references_column
FROM     user_constraints uc
,        user_cons_columns ucc1
,        user_cons_columns ucc2
WHERE    uc.constraint_name = ucc1.constraint_name
AND      uc.r_constraint_name = ucc2.constraint_name
AND      ucc1.POSITION = ucc2.POSITION -- Correction for multiple column primary keys.
AND      uc.constraint_type = 'R'
ORDER BY ucc1.TABLE_NAME
,        uc.constraint_name;

delete from organizations;

insert into organizations values(1, 'LU', null, 'ACADEMIC');
insert into organizations values(2, 'RTU', null, 'ACADEMIC');
insert into organizations values(3, 'TSI', null, 'ACADEMIC');
insert into organizations values(4, 'Accenture', null, 'BUSINESS');
insert into organizations values(5, 'Tieto', null, 'BUSINESS');
insert into organizations values(6, 'CTCo', null, 'BUSINESS');
insert into organizations values(7, 'Exigen', null, 'BUSINESS');
insert into organizations values(8, 'Intrum SDC', null, 'BUSINESS');
insert into organizations values(9, 'Finanšu ministrija', null, 'GOVERNMENT');
insert into organizations values(10, 'CSDD', null, 'GOVERNMENT');
insert into organizations values(11, 'R?gas dome', null, 'GOVERNMENT');
insert into organizations values(12, 'Albert hotel', null, 'BUSINESS');
insert into organizations values(13, 'Zin?t?u akad?mija', null, 'ACADEMIC');
insert into organizations values(14, 'Reval Hotel Latvija', null, 'BUSINESS');
-------------------------------------------PERSONS 	
--ID	NUMBER(6,0)	No
--FIRSTNAME	VARCHAR2(50 BYTE)	No
--LASTNAME	VARCHAR2(50 BYTE)	No
--EMAIL	VARCHAR2(50 BYTE)	No
--PHONE	VARCHAR2(20 BYTE)	Yes
--IS_ACCOMMODATION_REQUIRED	NUMBER(1,0)	Yes
--IS_ASSISTANCE_REQUIRED	NUMBER(1,0)	Yes
--ORGANIZATION_ID	NUMBER(6,0)	Yes
delete from persons;
insert into persons values(1, 'Antons', 'Anc?ns', 'aa@inbox.lv', '+37129493631', 0, 0, 1);
insert into persons values(2, 'Bart', 'Simpson', 'bart@simpsons.com', null, 1, 0, 1);
insert into persons values(3, 'Ceasar', 'Canini', 'czar@outlook.com', null, 1, 1, null);
insert into persons values(4, 'D?vids', 'Davidovs', 'dada@inbox.lv', null, 0, 1, null);
insert into persons values(5, 'Em?ls', 'Ernstsons', 'eee@gmail.com', '+37129493632', 0, 0, 2);
insert into persons values(6, 'Fedors', 'Fadejevs', 'fedja@gmail.com', null, 0, 0, 3);
insert into persons values(7, 'Gatis', 'Garais', 'garaisg@inbox.lv', null, 0, 0, 4);
insert into persons values(8, 'Hel?na', 'Heine', 'heine@gmail.com', null, 1, 0, 9);
insert into persons values(9, 'Ivo', 'Irbe', 'ivo@outlook.com', null, 1, 0, 10);
insert into persons values(10, 'J?nis', 'Jonins', 'j.jonins@gmail.com', null, 0, 0, null);


insert into persons values(11, 'K?rlis', 'Karlsons', 'karlisk@karlis.lv', null, 1, 0, 1);
insert into persons values(12, 'Leo', 'Leontjevs', 'lleo@gmail.com', null, 1, 0, 2);
insert into persons values(13, 'M?ris', 'Mežeckis', 'maris123@gmail.com', null, 1, 0, 3);
insert into persons values(14, 'Nils', 'Nabokovs', 'nn@outlook.com', null, 1, 0, 4);
insert into persons values(15, 'Oskars', 'Ork?ns', 'orkans@inbox.lv', null, 1, 0, 5);

-- helpteam
insert into persons values(16, 'P?teris', 'Pirmais', 'pirmais@mail.ru', null, 0, 0, null);
insert into persons values(17, 'Rudolfs', 'Briedis', 'rb@inbox.lv', null, 0, 0, 1);
insert into persons values(18, 'Santa', 'Sarkan?', 'ss@inbox.lv', null, 0, 0, 1);
insert into persons values(19, 'Talivaldis', 'Tievais', 'tievais@inbox.lv', null, 0, 0, 1);
insert into persons values(20, 'Uldis', 'Untums', 'untums2001@inbox.lv', null, 0, 0, 1);
insert into persons values(21, 'Valdis', 'Vilnis', 'heiheihei@gmail.com', null, 0, 0, 1);
insert into persons values(22, 'Zigurds', 'Zebiekste', 'zz@inbox.lv', null, 0, 0, 1);
insert into persons values(23, 'Ansis', 'Alun?ns', 'mansepasts@inbox.lv', null, 0, 0, 1);
insert into persons values(24, 'Boriss', 'Bekers', 'best@mail.de', null, 0, 0, null);
insert into persons values(25, 'Charles', 'Chester', 'charles@yahoo.lv', null, 0, 0, null);

insert into persons values(26, 'Daniels', 'D?rzi?š', 'dd@inbox.lv', null, 1, 1, null);
insert into persons values(27, 'Eduards', 'Eiž?ns', 'edd@inbox.lv', null, 1, 1, null);
insert into persons values(28, 'Felikss', 'Feinais', 'feinais@inbox.lv', null, 1, 1, null);
insert into persons values(29, 'George', 'Gentlemen', 'gentl@inbox.lv', null, 1, 1, null);
insert into persons values(30, 'Harry', 'Hoodiny', 'hh@inbox.lv', null, 1, 1, null);
insert into persons values(31, 'Ija', '?l?na', 'ija@inbox.lv', null, 1, 1, null);
insert into persons values(32, 'Jakobs', 'Jaunais', 'jaunais@inbox.lv', null, 1, 1, null);
insert into persons values(33, 'Kristaps', 'Kr?ms', 'krums@inbox.lv', null, 1, 1, null);

-------------------------------------------LOCATIONS 	
--ID	NUMBER(6,0)	No
--ORGANIZATION_ID	NUMBER(5,0)	No
--ADDRESS	VARCHAR2(100 BYTE)	No
--HAS_PARKING	NUMBER(1,0)	Yes
delete from locations;
insert into locations values(1, 1, 'Rai?a 19', 0);
insert into locations values(2, 11, 'Novembra krastmala', 0);
insert into locations values(8, 11, 'Centr?ltirgus', 0);
insert into locations values(10, 1, 'Rai?a 29', 0);
insert into locations values(5, 11, 'Doma laukums 1', 0);
insert into locations values(6, 12, 'Dzirnavu 33', 0);
insert into locations values(3, 4, 'Br?v?bas 219', 1);
insert into locations values(9, 13, 'Akad?mijas laukums 1', 0);
insert into locations values(4, 11, 'Melngalvju nams', 1);
insert into locations values(7, 2, 'Ka??u 1', 0);
insert into locations values(11, 14, 'Elizabetes 55', 1);
-------------------------------------------AUDITORIUMS	
--ID	NUMBER(6,0)	No
--LOCATION_ID	NUMBER(6,0)	No
--AUDITORIUM	VARCHAR2(30 BYTE)	No
--PLACES	NUMBER(3,0)	Yes
--HAS_WORKSTATION	NUMBER(1,0)	Yes
--select * from auditoriums;
insert into auditoriums values(1, 1, 'Liel? aula', 100, 0);
insert into auditoriums values(2, 1, '345', 30, 1);
insert into auditoriums values(3, 6, 'Konferencz?le 1', 80, 0);
insert into auditoriums values(4, 4, 'Sarkan? z?le', 200, 0);
insert into auditoriums values(5, 1, '1.kabinets', 10, 0);
insert into auditoriums values(6, 3, '219', 40, 0);
insert into auditoriums values(7, 10, 'Datortelpa', 40, 1);
insert into auditoriums values(8, 9, 'Galven? z?le', 100, 0);
insert into auditoriums values(9, 7, 'Liel? aula RTU', 100, 0);
insert into auditoriums values(10, 2, 'Novembra krastmala', 999, 0);
SELECT * FROM AUDITORIUMS;
-------------------------------------------HOTELS	
insert into hotels values(1, 6, 4, 45.00, 10);
insert into hotels values(2, 11, 5, 55, 20);
-------------------------------------------ACCOMMODATIONS	
--ID
--HOTEL_ID
--PERSON_ID
--START_DATE
--END_DATE

--insert into persons values(2, 'Bart', 'Simpson', 'bart@simpsons.com', null, 1, 0, 1);
--insert into persons values(3, 'Ceasar', 'Canini', 'czar@outlook.com', null, 1, 1, null);
--insert into persons values(8, 'Hel?na', 'Heine', 'heine@gmail.com', null, 1, 0, 9);
--insert into persons values(9, 'Ivo', 'Irbe', 'ivo@outlook.com', null, 1, 0, 10);
delete from accommodations;
INSERT INTO ACCOMMODATIONS VALUES(1, 1, 2, to_date('01.07.2013', 'DD.MM.YYYY'), to_date('04.07.2013', 'DD.MM.YYYY'));
INSERT INTO ACCOMMODATIONS VALUES(2, 1, 3, to_date('01.07.2013', 'DD.MM.YYYY'), to_date('07.07.2013', 'DD.MM.YYYY'));
INSERT INTO ACCOMMODATIONS VALUES(3, 1, 8, to_date('01.07.2013', 'DD.MM.YYYY'), to_date('07.07.2013', 'DD.MM.YYYY'));
INSERT INTO ACCOMMODATIONS VALUES(4, 1, 9, to_date('01.07.2013', 'DD.MM.YYYY'), to_date('07.07.2013', 'DD.MM.YYYY'));
INSERT INTO ACCOMMODATIONS VALUES(5, 1, 11, to_date('01.07.2013', 'DD.MM.YYYY'), to_date('07.07.2013', 'DD.MM.YYYY'));
INSERT INTO ACCOMMODATIONS VALUES(6, 2, 2, to_date('05.07.2013', 'DD.MM.YYYY'), to_date('07.07.2013', 'DD.MM.YYYY'));
INSERT INTO ACCOMMODATIONS VALUES(7, 2, 12, to_date('01.07.2013', 'DD.MM.YYYY'), to_date('07.07.2013', 'DD.MM.YYYY'));
INSERT INTO ACCOMMODATIONS VALUES(8, 2, 13, to_date('01.07.2013', 'DD.MM.YYYY'), to_date('07.07.2013', 'DD.MM.YYYY'));
INSERT INTO ACCOMMODATIONS VALUES(9, 2, 14, to_date('01.07.2013', 'DD.MM.YYYY'), to_date('07.07.2013', 'DD.MM.YYYY'));
INSERT INTO ACCOMMODATIONS VALUES(10, 2, 15, to_date('01.07.2013', 'DD.MM.YYYY'), to_date('07.07.2013', 'DD.MM.YYYY'));
-------------------------------------------CONFERENCES	
--CODE	VARCHAR2(10 BYTE)
--TITLE	VARCHAR2(50 BYTE)
--START_DATE	DATE
--END_DATE	DATE
delete from conferences;

insert into conferences values('LVFOOD2012', 'Latvijas p?rtikas ražot?ju konference 2012', '2012-09-01', '2012-09-10');
insert into conferences values('LVFOOD2013', 'Latvijas p?rtikas ražot?ju konference 2013', '2013-09-01', '2013-09-10');
insert into conferences values('LVFOOD2014', 'Latvijas p?rtikas ražot?ju konference 2014', '2014-09-01', '2014-09-10');

insert into conferences values('LVIT2012', 'IT Wildcard conference 2012', '2012-07-01', '2012-07-07');
insert into conferences values('LVIT2013', 'IT Wildcard conference 2013', '2013-07-01', '2013-07-07');
insert into conferences values('LVIT2014', 'IT Wildcard conference 2014', '2014-07-01', '2014-07-07');

insert into conferences values('LVFIN2012', 'Finances 2012', '2012-04-01', '2012-04-10');
insert into conferences values('LVFIN2013', 'Finances 2013', '2013-04-01', '2013-04-10');
insert into conferences values('LVFIN2014', 'Finances 2014', '2014-04-01', '2014-04-10');

insert into conferences values('LVBIO2014', 'Biotehnologies 2014', '2014-09-01', '2014-09-10');
-------------------------------------------SECTIONS	
insert into sections values(1, 'Web development', 'LVIT2013');
insert into sections values(2, 'Enterprise development', 'LVIT2013');
insert into sections values(3, 'Networks', 'LVIT2013');
insert into sections values(4, 'Robotics and embedded', 'LVIT2013');
insert into sections values(5, 'Databases', 'LVIT2013');
insert into sections values(6, 'Mobile development', 'LVIT2013');
insert into sections values(7, 'Game development', 'LVIT2013');
insert into sections values(8, 'IT project management', 'LVIT2013');
insert into sections values(9, 'Functional programming', 'LVIT2013');
insert into sections values(10, 'IT legislation', 'LVIT2013');

-------------------------------------------REFERATS	
--ID	NUMBER(6,0)
--SECTION_ID	NUMBER(6,0)
--TITLE	VARCHAR2(50 BYTE)
--DESCRIPTION	VARCHAR2(2000 BYTE)
SELECT * FROM referats;
delete from referats;
insert into referats(id, section_id, title, description)  values(1, 1, 'HTML5', 'Newest HTML standard');
insert into referats(id, section_id, title) values(2, 1, 'CSS3');
insert into referats(id, section_id, title, description) values(3, 1, 'Server-side Javascript in practice', 'Node.js usecases');
insert into referats(id, section_id, title) values(4, 5, 'Oracle 11g');
insert into referats(id, section_id, title) values(5, 5, 'Non-SQL');
insert into referats(id, section_id, title) values(6, 6, 'Android development best practices');
insert into referats(id, section_id, title) values(7, 1, 'Agile 2.0');
insert into referats(id, section_id, title) values(8, 9, 'Clojure');
insert into referats(id, section_id, title) values(9, 4, 'Arduino');
insert into referats(id, section_id, title, description) values(10, 2, 'Java vs .NET', 'holywar');
-------------------------------------------REFERAT_PARTS	
delete from referat_parts;
insert into referat_parts values('THESIS', 30);
insert into referat_parts values('TEXT', 50);
insert into referat_parts values('PHOTO', 20);
-------------------------------------------REFERAT_PARTS_SUBMITTED	
delete from referat_parts_submitted;
insert into referat_parts_submitted values(1, 'THESIS', '2013-06-01');
insert into referat_parts_submitted values(1, 'TEXT', '2013-06-01');
insert into referat_parts_submitted values(1, 'PHOTO', '2013-06-01');
insert into referat_parts_submitted values(2, 'THESIS', '2013-06-01');
insert into referat_parts_submitted values(2, 'TEXT', '2013-06-01');
insert into referat_parts_submitted values(2, 'PHOTO', '2013-06-01');
insert into referat_parts_submitted values(3, 'THESIS', '2013-06-01');
insert into referat_parts_submitted values(4, 'TEXT', '2013-06-01');
insert into referat_parts_submitted values(5, 'THESIS', '2013-06-01');
insert into referat_parts_submitted values(5, 'PHOTO', '2013-06-01');
-------------------------------------------LECTURES	
DELETE FROM LECTURES;

insert into lectures(id, is_workshop, referat_id, auditorium_id, start_datetime, end_datetime, is_free) 
values(1, 0, 1, 1, to_date('2013-07-01 09:00', 'YYYY-MM-DD HH24:MI'), to_date('2013-07-01 11:00', 'YYYY-MM-DD HH24:MI'), 1);

insert into lectures(id, is_workshop, referat_id, auditorium_id, start_datetime, end_datetime, is_free) 
values(2, 0, 2, 2, to_date('2013-07-01 11:00', 'YYYY-MM-DD HH24:MI'), to_date('2013-07-01 13:00', 'YYYY-MM-DD HH24:MI'), 1);

insert into lectures(id, is_workshop, referat_id, auditorium_id, start_datetime, end_datetime, is_free) 
values(3, 0, 3, 4, to_date('2013-07-01 15:00', 'YYYY-MM-DD HH24:MI'), to_date('2013-07-01 16:00', 'YYYY-MM-DD HH24:MI'), 1);

insert into lectures(id, is_workshop, referat_id, auditorium_id, start_datetime, end_datetime, is_free) 
values(4, 0, 4, 5, to_date('2013-07-02 09:00', 'YYYY-MM-DD HH24:MI'), to_date('2013-07-02 10:00', 'YYYY-MM-DD HH24:MI'), 1);

insert into lectures(id, is_workshop, referat_id, auditorium_id, start_datetime, end_datetime, is_free) 
values(5, 0, 5, 6, to_date('2013-07-02 10:00', 'YYYY-MM-DD HH24:MI'), to_date('2013-07-02 11:00', 'YYYY-MM-DD HH24:MI'), 1);

insert into lectures(id, is_workshop, referat_id, auditorium_id, start_datetime, end_datetime, is_free) 
values(6, 0, 6, 8, to_date('2013-07-02 11:00', 'YYYY-MM-DD HH24:MI'), to_date('2013-07-02 12:00', 'YYYY-MM-DD HH24:MI'), 1);

insert into lectures(id, is_workshop, referat_id, auditorium_id, start_datetime, end_datetime, is_free) 
values(7, 1, 7, 9, to_date('2013-07-02 14:00', 'YYYY-MM-DD HH24:MI'), to_date('2013-07-02 15:00', 'YYYY-MM-DD HH24:MI'), 1);

insert into lectures(id, is_workshop, referat_id, auditorium_id, start_datetime, end_datetime, is_free) 
values(8, 1, 8, 2, to_date('2013-07-02 15:00', 'YYYY-MM-DD HH24:MI'), to_date('2013-07-02 16:00', 'YYYY-MM-DD HH24:MI'), 1);

insert into lectures(id, is_workshop, referat_id, auditorium_id, start_datetime, end_datetime, is_free) 
values(9, 1, 9, 7, to_date('2013-07-02 16:00', 'YYYY-MM-DD HH24:MI'), to_date('2013-07-02 17:00', 'YYYY-MM-DD HH24:MI'), 1);

insert into lectures(id, is_workshop, referat_id, auditorium_id, start_datetime, end_datetime, is_free) 
values(10, 1, 10, 6, to_date('2013-07-02 17:00', 'YYYY-MM-DD HH24:MI'), to_date('2013-07-02 18:00', 'YYYY-MM-DD HH24:MI'), 1);

-------------------------------------------RATINGS	
insert into ratings values('not liked');
insert into ratings values('ok');
insert into ratings values('good');
insert into ratings values('perfect');
-------------------------------------------PARTICIPANTS	
delete from participants;
insert into participants values(1, 1, null, 0);
insert into participants values(1, null, 0);
insert into participants values(3, 1, null, 0);
insert into participants values(4, 1, null, 0);
insert into participants values(5, 1, null, 0);
insert into participants values(1, 2, null, 0);
insert into participants values(2, 2, null, 0);
insert into participants values(3, 2, null, 0);
insert into participants values(7, 2, null, 0);
insert into participants values(8, 2, null, 0);
insert into participants values(9, 3, null, 0);

-------------------------------------------LECTURERS	
insert into lecturers values(1, 6, 1);
insert into lecturers values(2, 4, 2);
insert into lecturers values(3, 6, 3);
insert into lecturers values(4, 4, 4);
insert into lecturers values(5, 3, 5);
insert into lecturers values(6, 3, 6);
insert into lecturers values(7, 5, 7);
insert into lecturers values(8, 6, 8);
insert into lecturers values(9, 5, 9);
insert into lecturers values(10, 8, 10);
-------------------------------------------HELPTEAM	
insert into helpteam values(16, 0, 0);
insert into helpteam values(17, 1, 0);
insert into helpteam values(18, 0, 0);
insert into helpteam values(19, 0, 0);
insert into helpteam values(21, 1, 0);
insert into helpteam values(22, 1, 1);
insert into helpteam values(23, 0, 1);
insert into helpteam values(24, 0, 1);
insert into helpteam values(25, 1, 1);
insert into helpteam values(20, 1, 1);
-------------------------------------------ASSISTANCE	
insert into assistance values(16, 3);
insert into assistance values(16, 4);
insert into assistance values(17, 26);
insert into assistance values(18, 27);
insert into assistance values(19, 28);
insert into assistance values(20, 29);
insert into assistance values(21, 30);
insert into assistance values(22, 31);
insert into assistance values(23, 32);
insert into assistance values(24, 33);
-------------------------------------------CARS 	
--LICENCE_PLATE	VARCHAR2(6 BYTE)	No
--MANUFACTURER	VARCHAR2(20 BYTE)	Yes
--MODEL	VARCHAR2(20 BYTE)	Yes
--YEAR	DATE	Yes
--IS_AVAILABLE	NUMBER(1,0)	Yes
--DRIVER_PERSON_ID	NUMBER(6,0)	Yes
alter table cars modify (year number);
insert into cars values('AA1234', 'Toyota', 'Corolla', 2006, 1, 16);
insert into cars values('AA1235', 'Toyota', 'Corolla', 2007, 1, 16);
insert into cars values('AA1236', 'Toyota', 'Yaris', 2012, 1, 17);
insert into cars values('AA1237', 'VW', 'Polo', 2008, 1, 18);
insert into cars values('AA1238', 'VW', 'Golf', 2009, 1, 18);
insert into cars values('AA1239', 'VW', 'Golf', 2009, 0, 19);
insert into cars values('AA1240', 'Opel', 'Astra', 2006, 1, 20);
insert into cars values('AA1241', 'Opel', 'Astra', 2013, 0, 22);
insert into cars values('AA1242', 'Hyundai', 'i30', 2013, 1, 24);
insert into cars values('AA1243', 'KIA', 'Ceed', 2013, 1, 24);

----------------------------------------------------------------------
----------------------------------------------------------------------
------------------------------------------------- ZI?AS PAR REFERATIEM
----------------------------------------------------------------------
----------------------------------------------------------------------

--flagstart

select * from persons order by id;

select * from lectures;

select * from referats;

select *
from persons
where 1=1 
and id in (select person_id from lecturers)
and id not in (select person_id from participants)
--and id in (select person_id from participants)
;



select * from lectures;

-- cik refer?tiem nekas nav iesniegts
select count(referats.id)
from referats
where referats.id not in (
  select referat_id
  from referat_parts_submitted
);
-- cik refer?tiem iensiegta t?ze
select count(referats.id)
from referats
where referats.id in (
  select referat_id
  from referat_parts_submitted s
  where s.referat_part = 'THESIS'
);
-- cik refer?tiem iensiegta TIKAI t?ze
select count(referats.id)
from referats
where referats.id in (
  select referat_id
  from referat_parts_submitted s
  where s.referat_part = 'THESIS'
) and referats.id not in (
  select referat_id
  from referat_parts_submitted s
  where s.referat_part <> 'THESIS'
);
-- cik refer?ti ir iesniegti piln?b?
select count(referats.id)
from referats
where referats.id in (
  select referat_id
  from referat_parts_submitted 
  group by referat_id
  having count(referat_part) = 3
);

-- cik refer?tiem kuras sadalas ir iesniegtas
select 
  parts.part, 
  count(referat_id)
from 
  referat_parts parts, 
  referat_parts_submitted submitted
where submitted.referat_part = parts.part
group by parts.part
;


----------------------------------------------------------------------
----------------------------------------------------------------------
------------------------------------------------- PAPILDUS
----------------------------------------------------------------------
----------------------------------------------------------------------

-- zi?as par visiem lekciju klaus?t?jiiem
select distinct persons.*
from persons, participants
where persons.id = participants.person_id
;
-- zi?as par visiem lektoriem
select distinct persons.*
from persons, lecturers
where persons.id = LECTURERS.person_id
;
-- cik daudz ir t?du lektoru, kas ar? ir klaus?t?ji cit?s lekcij?s?
select count(persons.id)
from persons
where persons.id in (
  select person_id from lecturers
)
and persons.id in (
  select person_id from participants
)
;
-- dal?bnieki pa šodienas lekcij?m
select 
  lectures.auditorium_id,
  lectures.start_datetime,
  referats.title,
  persons.firstname,
  persons.lastname  
from lectures, referats, participants, persons
where lectures.referat_id = referats.id
and participants.lecture_id = lectures.id
and persons.id = participants.person_id
and lectures.start_datetime >= trunc(sysdate)
;
-- cik ir refer?tu pa sekcij?m?
select sections.title, count(referats.id)
from sections, referats
where referats.section_id = sections.id
group by sections.title
;

-- vai ir sekcijas, kur tika iensniegts tikai viens refer?ts?
select sections.title, count(referats.id)
from sections, referats
where referats.section_id = sections.id
group by sections.title
having count(referats.id) = 1
;

-- cik dal?bnieku piere?istr?j?s, bet nepiedal?j?s?
select count(*) from participants where checked_in is null or checked_in = 0;


-- kura bija popul?r?k? p?c apm?kl?t?bas lekcija? refer?ts? sekcija? lektors?
select l.id
from lectures l, participants p
where p.lecture_id = l.id 
GROUP BY l.ID
having count(*) = (
  select max(count(*))
  from lectures l, participants p
  where p.lecture_id = l.id 
  GROUP BY l.ID
)
;

-- kura bija lab?k? p?c nov?rt?juma (visvair?k "perfect" atz?mju) lekcija? refer?ts? sekcija? lektors?
select l.id
from lectures l, participants p
where p.lecture_id = l.id 
and p.rating = 'perfect'
group by l.id
having count(*) = (
  select max(count(*))
  from lectures l, participants p
  where p.lecture_id = l.id 
  and p.rating = 'perfect'
  GROUP BY l.ID 
)
;

-- kurš dal?bnieks apmekl?jis visvair?k lekciju?
select p.person_ID
from lectures l, participants p
where p.lecture_id = l.id 
GROUP BY p.person_ID
having count(*) = (
  select max(count(*))
  from lectures l, participants p
  where p.lecture_id = l.id 
  GROUP BY p.person_ID
)
;

-- kuras lekcijas tika las?tas, kaut referats nebija gatavs piln?b??
-- kuras lekcijas ir noz?m?tas, kaut referats nebija gatavs piln?b??
select * from lectures where referat_id in (
  select referat_id
  from referat_parts_submitted 
  GROUP BY referat_id
  having count(*) < 3
)
--and start_datetime < (sysdate+30)
;

-- kura lekcija nesa??ma nevienu "nepatika" nov?rt?jumu?
select lecture_id 
from participants 
minus
select lecture_id 
from participants 
where rating = 'not liked';
-- vai bija lekcijas- praktisk?s nodarb?bas (workshop), kas notika nepiemerot?s telp?s (has_workstations =0)? 
-- cik lekciju notika konferencz?l?s viesn?c?s?
-- vai bija gad?jumi, kad cilv?ki nevar?ja ietilpt lekcijas auditorij??
-- kuras telpas ir br?vas šodien, s?kot no plkst 14 l?dz (neieskaitot) 16?
-- cik daudz refer?tu pilno tekstu tika iesniegt p?dej? br?d? - pirm?s lekcijas dien??
-- nosakot svarus (%) refer?tu dal?m, var r??inat to gatav?bu procentu?li
-- vai taisn?ba, ka refer?tiem ar foto ir vid?ji augst?ks nov?rt?jums?
-- atbrauks jauna deleg?cija; jums jasazinas ar viesn?c?m un j?atjauno pieejamo istabu skaits; atrodiet kontaktus (epastus un tel) viesn?c?m


-- piem?ri SQL teikumiem, kas ..
-- .. pievieno,
insert into conferences values (
  'LVFood2013', 
  'Latvijas piena p?rstr?d?t?ju izst?de 2013',
  to_date('01.07.2013', 'DD.MM.YYYY'),
  to_date('10.07.2013', 'DD.MM.YYYY')
);  
-- .. maina,
update conferences 
set title = 'Latvijas p?rtikas r?pniec?bas izst?de 2013'
where code = 'LVFood2013';  
-- .. dz?š inform?ciju
delete from conferences where code = 'LVFood2013';


select distinct p.firstname
from lecturers l
inner join persons p
  on l.person_id = p.id
order by l.id;
