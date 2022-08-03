-- Keep a log of any SQL queries you execute as you solve the mystery.
.tables
.schema
.schema crime_scene_reports

-- look at the crime scene reports in descriptions

SELECT description FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28;

-- look at Humphery street bakery, Interviews are conducted on that date
-- three witnesses

.schema bakery_security_logs, interviews

