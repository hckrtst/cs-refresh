PRAGMA foreign_keys = ON;

CREATE TABLE company (
  companyName TEXT,
  id INTEGER primary key
);
CREATE TABLE employeeshired (
  id INTEGER primary key,
  numHired INTEGER,
  fiscalQuarter INTEGER,
  foreign key (id) references Company
);

insert into company VALUES
  ("Harrison Group", 34),
  ("Sherry Computing", 2),
  ("Paranoid Security Inc", 10);

insert into employeeshired(id, numHired, fiscalQuarter) VALUES
  (34, 190, 4),
  (2, 34 ,2);
