
CREATE TABLE [Teacher](
    [Teacher_ID] [int] NOT NULL,
    [Name] [nvarchar](50) NULL,
    [Surname] [nvarchar](50) NULL,
    [Mentor_ID] [int] NULL,
 CONSTRAINT [PK_Teacher] PRIMARY KEY CLUSTERED
(
    [Teacher_ID] ASC
)
)
GO
/****** Object:  Table [Course]    Script Date: 12/22/2009 10:16:55 ******/

CREATE TABLE [Course](
    [Course_ID] [int] NOT NULL,
    [Name] [nvarchar](100) NULL,
 CONSTRAINT [PK_Course] PRIMARY KEY CLUSTERED
(
    [Course_ID] ASC
)
)
GO
/****** Object:  Table [Student]    Script Date: 12/22/2009 10:16:55 ******/

CREATE TABLE [Student](
    [Student_ID] [int] NOT NULL,
    [Name] [nvarchar](50) NULL,
    [Surname] [nvarchar](50) NULL,
 CONSTRAINT [PK_Student] PRIMARY KEY CLUSTERED
(
    [Student_ID] ASC
)
)
GO
/****** Object:  Table [Attendance]    Script Date: 12/22/2009 10:16:55 ******/

CREATE TABLE [Attendance](
    [Student_ID] [int] NULL,
    [Lecture_ID] [int] NULL,
    [Attendance] [nchar](1) NULL
)
GO
/****** Object:  Table [Grade]    Script Date: 12/22/2009 10:16:55 ******/

CREATE TABLE [Grade](
    [Examination_ID] [int] NULL,
    [Student_ID] [int] NULL,
    [Grading_teacher_ID] [int] NULL,
    [Grade] [int] NULL
)
GO
/****** Object:  Table [Examination]    Script Date: 12/22/2009 10:16:55 *****3. praktisk� darba skr*/

CREATE TABLE [Examination](
    [Examination_ID] [int] NOT NULL,
    [Course_ID] [int] NULL,
    [Responsible_teacher_ID] [int] NULL,
    [Date] [datetime] NULL,
    [Description] [nvarchar](50) NULL,
 CONSTRAINT [PK_Examination] PRIMARY KEY CLUSTERED
(
    [Examination_ID] ASC
)
)
GO
/****** Object:  Table [Course_teacher]    Script Date: 12/22/2009 10:16:55 ******/

CREATE TABLE [Course_teacher](
    [Course_ID] [int] NULL,
    [Teacher_ID] [int] NULL,
    [Start_date] [datetime] NULL,
    [End_date] [datetime] NULL
)
GO
/****** Object:  Table [Lecture]    Script Date: 12/22/2009 10:16:55 ******/

CREATE TABLE [Lecture](
    [Lecture_ID] [int] NOT NULL,
    [Room] [nchar](10) NULL,
    [Day] [datetime] NULL,
    [Time] [nchar](10) NULL,
    [Course_ID] [int] NULL,
    [Teacher_ID] [int] NULL,
 CONSTRAINT [PK_Lecture] PRIMARY KEY CLUSTERED
(
    [Lecture_ID] ASC
)
)
GO
/****** Object:  Table [Student_course]    Script Date: 12/22/2009 10:16:55 ******/

CREATE TABLE [Student_course](
    [Student_ID] [int] NULL,
    [Course_ID] [int] NULL
) ON [PRIMARY]
GO
/****** Object:  ForeignKey [FK_Attendance_Lecture]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [Attendance]  WITH CHECK ADD  CONSTRAINT [FK_Attendance_Lecture] FOREIGN KEY([Lecture_ID])
REFERENCES [Lecture] ([Lecture_ID])
GO
ALTER TABLE [Attendance] CHECK CONSTRAINT [FK_Attendance_Lecture]
GO
/****** Object:  ForeignKey [FK_Attendance_Student]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [Attendance]  WITH CHECK ADD  CONSTRAINT [FK_Attendance_Student] FOREIGN KEY([Student_ID])
REFERENCES [Student] ([Student_ID])
GO
ALTER TABLE [Attendance] CHECK CONSTRAINT [FK_Attendance_Student]
GO
/****** Object:  ForeignKey [FK_Course_teacher_Course]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [Course_teacher]  WITH CHECK ADD  CONSTRAINT [FK_Course_teacher_Course] FOREIGN KEY([Course_ID])
REFERENCES [Course] ([Course_ID])
GO
ALTER TABLE [Course_teacher] CHECK CONSTRAINT [FK_Course_teacher_Course]
GO
/****** Object:  ForeignKey [FK_Course_teacher_Teacher]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [Course_teacher]  WITH CHECK ADD  CONSTRAINT [FK_Course_teacher_Teacher] FOREIGN KEY([Teacher_ID])
REFERENCES [Teacher] ([Teacher_ID])
GO
ALTER TABLE [Course_teacher] CHECK CONSTRAINT [FK_Course_teacher_Teacher]
GO
/****** Object:  ForeignKey [FK_Examination_Course]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [Examination]  WITH CHECK ADD  CONSTRAINT [FK_Examination_Course] FOREIGN KEY([Course_ID])
REFERENCES [Course] ([Course_ID])
GO
ALTER TABLE [Examination] CHECK CONSTRAINT [FK_Examination_Course]
GO
/****** Object:  ForeignKey [FK_Examination_Teacher]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [Examination]  WITH CHECK ADD  CONSTRAINT [FK_Examination_Teacher] FOREIGN KEY([Responsible_teacher_ID])
REFERENCES [Teacher] ([Teacher_ID])
GO
ALTER TABLE [Examination] CHECK CONSTRAINT [FK_Examination_Teacher]
GO
/****** Object:  ForeignKey [FK_Grade_Examination]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [Grade]  WITH CHECK ADD  CONSTRAINT [FK_Grade_Examination] FOREIGN KEY([Examination_ID])
REFERENCES [Examination] ([Examination_ID])
GO
ALTER TABLE [Grade] CHECK CONSTRAINT [FK_Grade_Examination]
GO
/****** Object:  ForeignKey [FK_Grade_Student]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [Grade]  WITH CHECK ADD  CONSTRAINT [FK_Grade_Student] FOREIGN KEY([Student_ID])
REFERENCES [Student] ([Student_ID])
GO
ALTER TABLE [Grade] CHECK CONSTRAINT [FK_Grade_Student]
GO
/****** Object:  ForeignKey [FK_Grade_Teacher]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [Grade]  WITH CHECK ADD  CONSTRAINT [FK_Grade_Teacher] FOREIGN KEY([Grading_teacher_ID])
REFERENCES [Teacher] ([Teacher_ID])
GO
ALTER TABLE [Grade] CHECK CONSTRAINT [FK_Grade_Teacher]
GO
/****** Object:  ForeignKey [FK_Lecture_Course]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [Lecture]  WITH CHECK ADD  CONSTRAINT [FK_Lecture_Course] FOREIGN KEY([Course_ID])
REFERENCES [Course] ([Course_ID])
GO
ALTER TABLE [Lecture] CHECK CONSTRAINT [FK_Lecture_Course]
GO
/****** Object:  ForeignKey [FK_Lecture_Teacher]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [Lecture]  WITH CHECK ADD  CONSTRAINT [FK_Lecture_Teacher] FOREIGN KEY([Teacher_ID])
REFERENCES [Teacher] ([Teacher_ID])
GO
ALTER TABLE [Lecture] CHECK CONSTRAINT [FK_Lecture_Teacher]
GO
/****** Object:  ForeignKey [FK_Student_course_Course]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [Student_course]  WITH CHECK ADD  CONSTRAINT [FK_Student_course_Course] FOREIGN KEY([Course_ID])
REFERENCES [Course] ([Course_ID])
GO
ALTER TABLE [Student_course] CHECK CONSTRAINT [FK_Student_course_Course]
GO
/****** Object:  ForeignKey [FK_Student_course_Student]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [Student_course]  WITH CHECK ADD  CONSTRAINT [FK_Student_course_Student] FOREIGN KEY([Student_ID])
REFERENCES [Student] ([Student_ID])
GO
ALTER TABLE [Student_course] CHECK CONSTRAINT [FK_Student_course_Student]
GO
/****** Object:  ForeignKey [FK_Teacher_Teacher]    Script Date: 12/22/2009 10:16:55 ******/
ALTER TABLE [Teacher]  WITH CHECK ADD  CONSTRAINT [FK_Teacher_Teacher] FOREIGN KEY([Mentor_ID])
REFERENCES [Teacher] ([Teacher_ID])
GO
ALTER TABLE [Teacher] CHECK CONSTRAINT [FK_Teacher_Teacher]
GO