++ 4 saturiskās entītijas (tas neiekļauj starptabulas un kodifikatorus).
ok: Persons, Sections, Referats, Lections

++ Papildus tiek glabāti citi saistītie dati, kas nav prasīti uzdevuma nosacījumā
(vēl vismaz 4 saturiskas entītijas, starptabulas m:n saišu atrisināšanai netiek ieskaitītas)
Conferences, Organizations, Buildings, Auditoriums, Hotels, Cars

TABLES:

Organizations
    title
    contact_person
    type (academic/ business)

Persons
    firstname
    lastname
    email
    phone
    is_accommodation_required
    is_assistance_required
    organization_title

Cars
    manufacturer
    model
    year
    is_available

Buildings
    contact_person
    address

Auditoriums
    building_id
    room_nr
    places

Hotels
    price
    places

Participants
    person_id
    lecture_id
    ratings_id
    checked_in

Lecturers
    person_id
    referat_id

Helpteam

Ratings
    nepatika
    ok
    labi
    izcili

Conferences
    title
    start_date
    end_date

Sections
Referats
Lections
    date
    lection equipment?
    workshops? some reeferats have workshops
    free/ ticket price?
    without registration
    location_id
    is_workshop

Locations
    room_id


Referat_parts
    Thesis
    Text
    Photos
    Video

Referat_parts_submitted

Readinness_percentage
    part
    percentage
