-- To: girts.karnitis@lu.lv Subj: DBI MD1 aj05044

-- DBI MD1 aj05044 Andrejs Jurčenoks

-- TRANSPORTA LĪDZEKĻU REISU UZSKAITE:
-- Uzrakstīt tabulu izveides skriptu atbilstoši izveidotajam ER modelim:

-- Jāglabā informācija par transporta līdzekļiem – Valsts reģistrācijas Nr. (unikāls), ražotājs, modelis, izlaiduma gads, krāsa.
CREATE TABLE [cars] (
    [licence_plate] [varchar] (6) NOT NULL PRIMARY KEY,
    [manufacturer] [varchar] (50),
    [model] [varchar] (50),
    [year] [int],
    [color] [varchar] (50)
) ON [PRIMARY]
GO

-- Jāglabā informācija par šoferiem – Personas kods (unikāls), vārds, uzvārds, vadītāja apliecības nr.
CREATE TABLE [drivers] (
    [person_id] [int] NOT NULL PRIMARY KEY,
    [firstname] [varchar] (50) NOT NULL ,
    [lastname] [varchar] (50)  NOT NULL ,
    [driver_licence] [varchar] (50)  NOT NULL
) ON [PRIMARY]
GO

-- Jāsaglabā ziņas, kuru transporta līdzekli kuriem šoferiem ir atļauts vadīt.
-- Katru transporta līdzekli atļauts vadīt vairākiem šoferiem, katram šoferiem atļauts vadīt vairākus transporta līdzekļus.
CREATE TABLE [cars_drivers](
    [cars_driver_id] [int] IDENTITY (1, 1) NOT NULL PRIMARY KEY,
    [person_id] [int] NOT NULL,
    [licence_plate] [varchar] (6) NOT NULL
)
GO

-- Jāglabā ziņas par reisiem – kurā datumā no kurienes uz kurieni kurš šoferis ar kuru transporta līdzekli ir braucis, cik km nobraucis šī reisa laikā.
CREATE TABLE [trips](
    [trip_id] [int] IDENTITY (1, 1) NOT NULL PRIMARY KEY,
    [cars_driver_id] [int] NOT NULL,
    [trip_date] [datetime] NOT NULL,
    [trip_from] [varchar] (50) NOT NULL ,
    [trip_to] [varchar] (50) NOT NULL ,
    [kilometers] [int] NOT NULL
)
GO

ALTER TABLE [cars_drivers]
ADD  CONSTRAINT [FK_cars_drivers_driver] FOREIGN KEY([person_id])
REFERENCES [drivers] ([person_id])
GO

ALTER TABLE [cars_drivers]
ADD  CONSTRAINT [FK_cars_drivers_car] FOREIGN KEY([licence_plate])
REFERENCES [cars] ([licence_plate])
GO

ALTER TABLE [trips]
ADD  CONSTRAINT [FK_trips_cars_driver] FOREIGN KEY([cars_driver_id])
REFERENCES [cars_drivers] ([cars_driver_id])
GO

-- Atlasīt informāciju par visiem reisiem, kas notikuši 2012. gadā – reisa datums, No kurienes, uz kurieni, cik km nobraukti šī reisa laikā.
SELECT
    trip_date
    , trip_from
    , trip_to
    , kilometers
FROM
    trips
WHERE trip_date >= '2012-01-01'
AND   trip_date <  '2013-01-01'

-- Izveidot ER modeli Čena sintaksē.