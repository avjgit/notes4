-- To: girts.karnitis@lu.lv Subj: DBI PD KD2 aj05044 Andrejs Jurčenoks

-- Pieprasījums no vairākām tabulām ar nosacījumu
-- Atlasīt Pasniedzēju vārdu uzvārdu un kursa nosaukumu tiem kursiem,
-- kuros pasniedzējs ir lasījis kaut vienu lekciju, un kursa nosaukums sākas ar ‘Intro’.
SELECT DISTINCT
	 t.Name
	,t.Surname
	,c.Name 
FROM 
	Teacher t
	, Lecture l
	, Course c
WHERE
	t.Teacher_ID = l.Teacher_ID
AND c.Course_ID  = l.Course_ID
AND c.Name like 'Intro%'
;


-- Datu agregēšana un grupēšana
-- Atlasīt pasniedzēja ID un cik atzīmes viņš ir ielicis.

-- Atbilde A: vienkārši ar agregēšanu un grupēšanu (droši vien, kas bija prasīts)
SELECT Grading_teacher_ID, COUNT(*) grades
FROM Grade
GROUP BY Grading_teacher_ID
;

-- Atbilde B: atlase, lai rāda arī tiem pasniedzējiem, kas neielika atzīmi (count = 0)
SELECT 
	t.Teacher_ID, 
	(
		SELECT count(*)
		FROM Grade
		WHERE Grading_teacher_ID = t.Teacher_ID
	) grades
FROM Teacher t
;

-- Datu agregēšana un grupēšana ar nosacījumu
-- Atlasīt kursa ID un cik studentu uz šo kursu ir pieteikušies tiem kursiem,
-- uz kuriem ir pieteikušies vairāk nekā 60 studenti.
SELECT Course_ID, COUNT(*)
FROM Student_course
GROUP BY Course_ID
HAVING COUNT(*) > 60
;

-- Apakšpieprasījums lauka atlasē
-- Atlasīt pasniedzēja vārdu un uzvārdu un šī pasniedzēja ielikto atzīmju skaitu.
SELECT 
	t.Name, 
	t.Surname, 
	(
		SELECT count(*)
		FROM Grade
		WHERE Grading_teacher_ID = t.Teacher_ID
	) grades
FROM Teacher t
;

-- Apakšpieprasījums where nosacījumā
-- Atlasīt Kursa nosaukumu tiem kursiem,
-- uz kuriem nav pierakstījies neviens students ar vārdu ‘James’
SELECT c.Name
FROM Course c
WHERE c.Course_ID NOT IN (
	SELECT sc.Course_ID
	FROM Student_course sc, Student s
	WHERE sc.Student_ID = s.Student_ID
	AND s.Name = 'James'
)
;