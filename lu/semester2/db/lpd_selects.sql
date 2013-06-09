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
-- cik refer?tiem nekas nav iesniegts
select count(referats.id)
from referats
where referats.id not in (
  select referat_id
  from referat_parts_submitted
);
-- cik refer?tiem iensiegta tikai t?ze
select count(referats.id)
from referats
where referats.id in (
  select referat_id
  from referat_parts_submitted s
  where s.referat_part = 'THESIS'
) and referats.id in (
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
select parts.part, count(referat_id)
from referat_parts parts, referat_parts_submitted submitted
where submitted.referat_part = parts.part
group by parts.part
;

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

Izveidotais datu modelis lauj veidot š?dus interesantus piepras?jumus:
-- cik dal?bnieku piere?istr?j?s, bet nepiedal?j?s?
-- kura bija popul?r?k? p?c apm?kl?t?bas lekcija? refer?ts? sekcija? lektors?
-- kura bija lab?k? p?c nov?rt?juma lekcija? refer?ts? sekcija? lektors?
-- kurš dal?bnieks apmekl?jis visvair?k lekciju?
-- kuras lekcijas tika las?tas, kaut referats nebija gatavs piln?b??
-- kura lekcija nesa??ma nevienu "nepatika" nov?rt?jumu?
-- ja lekcija bija praktisk? nodarb?ba (workshop),
-- cik lekciju notika konferencz?l?s viesn?c?s?
-- vai bija gad?jumi, kad cilv?ki nevar?ja ietilpt lekcijas auditorij??
-- kura telpa ir br?va datum? s?kot no plkst 14 l?dz (neieskaitot) 16?
-- cik daudz refer?tu pilno tekstu tika iesniegt p?dej? br?d? - pirm?s lekcijas dien??
-- nosakot svarus (%) refer?tu dal?m, var r??inat to gatav?bu procentu?li
-- vai taisn?ba, ka refer?tiem ar foto ir vid?ji augst?ks nov?rt?jums?


-- atbrauks jauna deleg?cija; jums jasazinas ar viesn?c?m un j?atjauno pieejamo istabu skaits; atrodiet kontaktus (epastus un tel) viesn?c?m
