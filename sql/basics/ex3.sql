CREATE TABLE person (
    id INTEGER PRIMARY KEY,
    first_name TEXT,
    last_name TEXT,
    age INTEGER
);

CREATE TABLE pet (
    id INTEGER PRIMARY KEY,
    name TEXT,
    age INTEGER
);

create table person_pet (
    person_id INTEGER,
    pet_id INTEGER,
    foreign key (person_id) references person,
    foreign key (pet_Id) references pet
);

INSERT INTO person (id, first_name, last_name, age)
    VALUES (0, "Jane", "Smith", 27),
    (1, "Janet", "Hall", 17),
    (3, "Melody", "Graham", 13);

insert into pet(id, name, age)
  VALUES (0, "Flash", 2),
  (1, "Doozer", 4),
  (2, "Puggy", 2);

insert into person_pet VALUES
  (0, 1),
  (1, 0),
  (3, 2);
