-- To: girts.karnitis@lu.lv Subj: DBI MD1 aj05044
-- DBI KD1 aj05044 Andrejs Jurčenoks

-- Tabula Automasina
-- Nosaukums   Datu tips   Izmērs  Piezīmes
-- RegNr   Simbolu virkne ar fiksētu garumu    10  Primarā atslēga
-- Marka   Simbolu virkne ar mainīgu garumu    30  Nav Null
-- Modelis Simbolu virkne ar mainīgu garumu    25  Nav Null
-- IzlaidumaGads   Vesels skaitlis     Nav Null
-- Ipasnieks   Simbolu virkne ar mainīgu garumu    50  Var būt Null

CREATE TABLE [Automasina] (
     RegNr          [char]    (10) NOT NULL PRIMARY KEY
    ,Marka          [varchar] (30) NOT NULL
    ,Modelis        [varchar] (25) NOT NULL
    ,IzlaidumaGads  [int]          NOT Null
    ,Ipasnieks      [varchar] (50) COLLATE Latvian_CI_AI NULL
)
GO

-- Tabula Sods
-- Nosaukums   Datu tips   Izmērs  Piezīmes
-- ID  Vesels skaitlis     Automātiski numurējas, primārā atslēga
-- Izmers  Decimāldaļkaitlis, 2 cipari aiz komata  4,2 Nav Null
-- Parkapums   Simbolu virkne ar mainīgu garumu    100 Var būt  Null
-- Datums  Datums      Nav Null
-- AutoRegNr   Simbolu virkne ar fiksētu garumu    10  Ārējā atslēga. Norāde uz tabulu Automasina lauku RegNr

CREATE TABLE [Sods] (
     ID         [int] IDENTITY(1,1) NOT NULL PRIMARY KEY
    ,Izmers     [numeric] (4,2) NOT NULL
    ,Parkapums  [varchar] (100) COLLATE Latvian_CI_AI NULL
    ,Datums     [datetime] NOT NULL
    ,AutoRegNr  [char]    (10)
)
GO

ALTER TABLE [Sods]
ADD  CONSTRAINT [fk_sods_automasina_regnr] FOREIGN KEY([AutoRegNr])
REFERENCES [Automasina] ([RegNr])
GO

-- Automasina
-- RegNr   Marka   Modelis IzlaidumaGads   Ipasnieks
-- GT9354  Audi    A4  2010    Mērija Popinsa
-- BU9838  Opel    Vectra  2006    Mākoņpūka SIA
-- FU23    BMW 530 2011
-- HK9559  Citroen C5  2011    Jānis Zaļenieks

INSERT INTO Automasina (RegNr, Marka, Modelis, IzlaidumaGads, Ipasnieks)
VALUES('GT9354',  'Audi',    'A4',  2010,    'Mērija Popinsa')

INSERT INTO Automasina (RegNr, Marka, Modelis, IzlaidumaGads, Ipasnieks)
VALUES('BU9838',  'Opel',    'Vectra',  2006,    'Mākoņpūka SIA')

INSERT INTO Automasina (RegNr, Marka, Modelis, IzlaidumaGads, Ipasnieks)
VALUES('FU23',    'BMW', '530', 2011, NULL)

INSERT INTO Automasina (RegNr, Marka, Modelis, IzlaidumaGads, Ipasnieks)
VALUES('HK9559',  'Citroen', 'C5'  2011,    'Jānis Zaļenieks')


-- Sods
-- Izmers  Parkapums   Datums  AutoRegNr
-- 5.00    Stāvēšana neatļautā vietā   11.02.2013  GT9354
-- 40.00   Ātruma pārkāpšana   05.06.2012  HK9559
-- 200.00      09.04.2013  BU9838
-- 10.00   Neatļauta pagrieziena veikšana  14.03.2012  GT9354

INSERT INTO Sods (Izmers,  Parkapums,   Datums,  AutoRegNr)
VALUES (5.00,    'Stāvēšana neatļautā vietā',   11.02.2013,  'GT9354')

INSERT INTO Sods (Izmers,  Parkapums,   Datums,  AutoRegNr)
VALUES (40.00,   'Ātruma pārkāpšana',   05.06.2012, 'HK9559'

INSERT INTO Sods (Izmers,  Parkapums,   Datums,  AutoRegNr)
VALUES (200.00,  NULL,    09.04.2013,  'BU9838'

INSERT INTO Sods (Izmers,  Parkapums,   Datums,  AutoRegNr)
VALUES (10.00,   'Neatļauta pagrieziena veikšana',  14.03.2012,  'GT9354'

-- Izmainīt datus tabulā Automasina – Automašīnai  FU23 nomainīt īpašnieku  uz „Anna Pētersone”.
-- Izmainīt datus tabulā Automasina – Automašīnai  FU23 nomainīt īpašnieku  uz „Anna Pētersone”.

-- Izmainīt datus tabulā Sods – sodiem, kuriem izmers ir lielāks par 10Ls, uzstādīt lauku Datums vienādu ar 14.03.2013.
-- Izmainīt datus tabulā Sods – sodiem, kuriem izmers ir lielāks par 10Ls, uzstādīt lauku Datums vienādu ar 14.03.2013.

-- Atlasīt no tabulas Automasina  laukus RegNr, Marka, Modelis tām automašīnām, kurām izlaiduma gads ir lielāks pa 2010 vai vienāds ar  2010. Sakārtot pēc automašīnas markas dilstošā kārtībā un pēc modeļa augošā kārtībā.
-- Atlasīt no tabulas Automasina  laukus RegNr, Marka, Modelis tām automašīnām, kurām izlaiduma gads ir lielāks pa 2010 vai vienāds ar  2010. Sakārtot pēc automašīnas markas dilstošā kārtībā un pēc modeļa augošā kārtībā.

-- Atlasīt no tabulas Sods laukus AutoRegNr, Summa, Datums tiem pārkāpumiem, kuru izmers ir lielāks par 100Ls vai arī AutoRegNr satur ciparu 3.
-- Atlasīt no tabulas Sods laukus AutoRegNr, Summa, Datums tiem pārkāpumiem, kuru izmers ir lielāks par 100Ls vai arī AutoRegNr satur ciparu 3.

-- Izdzēst no tabulas Sods sodus, kuru izmers  ir lielāks par 20Ls.
-- Izdzēst no tabulas Sods sodus, kuru izmers  ir lielāks par 20Ls.

-- Izdzēst visus datus no tabulas Automasina un tabulas Sods.
-- Izdzēst visus datus no tabulas Automasina un tabulas Sods.
