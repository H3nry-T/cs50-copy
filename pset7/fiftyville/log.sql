-- Keep a log of any SQL queries you execute as you solve the mystery.
.tables
.schema
.schema crime_scene_reports

-- look at the crime scene reports in descriptions

SELECT description FROM crime_scene_reports
WHERE street LIKE "H%" AND year = 2021 AND month = 7 AND day = 28;
-- 10:15 crime committed at Humphery street bakery

-- look at Humphery street bakery, Interviews are conducted on that date
-- three witnesses

.schema bakery_security_logs
.schema interviews

--take a look at the interview logs
SELECT name, transcript FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";
-- Ruth Eugene Raymond gives good information






-- Ruth: parking lot security camera 10 mins after the theif steals something.
SELECT * FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;

--===================================================================================== PARKING LOT
-- license_plates, but we need names:
SELECT DISTINCT name FROM people
WHERE people.license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25
);
-- identifies Vanessa, Barry, Iman, Sofia, Luca, Diana, Kelsey, Bruce
--
--
--
-- Eugene: morning ATM Legget street
SELECT * FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
-- use people, bank_accounts, atm_transactions
--============================================================================================================ ATM MACHINE
SELECT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
-- identifies: Bruce, Diana, Brooke, Kenny, Iman, Luca, Taylor, Benista.
--
--
--
-- Raymond: phone call to a friend to purchase a flight ticket tommorow 29th july.
SELECT * FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;
-- phone_calls, people,
--================================================================================= CALLER
SELECT DISTINCT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;
--callers: Sofia, Kelsey, Bruce, Kelsey, Taylor, Diana, Carina, Kenny, Benista.

SELECT name FROM people
JOIN phone_calls ON phone_calls.receiver = people.phone_number
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;
--receivers: Jack, Larry, Robin, Melissa, James, Philip, Jacqueline, Doris, Anna.




-- find the earliest flight from that time
SELECT * FROM flights
WHERE year = 2021 AND month = 7 AND day = 29
ORDER BY hour LIMIT 1;
-- id 36, fiftyville to new york flight


-- passengers, flights, airports, people
--find the city name:
SELECT flights.id, city FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE airports.id IN (
    SELECT destination_airport_id FROM flights
    WHERE year = 2021 AND month = 7 AND day = 29
    ORDER BY hour LIMIT 1
) AND year = 2021 AND month = 7 AND day = 29;

--=================================================================================== PASSENGERS
--flights, passengers, to get the passport number for all passangers on the flight.
SELECT DISTINCT name FROM people
WHERE passport_number IN (

    SELECT passport_number FROM passengers
    JOIN flights ON flights.id = passengers.flight_id
    WHERE flights.id = (
        SELECT flights.id FROM airports
        JOIN flights ON airports.id = flights.destination_airport_id
        WHERE airports.id IN (
        SELECT destination_airport_id FROM flights
        WHERE year = 2021 AND month = 7 AND day = 29
        ORDER BY hour LIMIT 1
        ) AND year = 2021 AND month = 7 AND day = 29
    )
    AND year = 2021 AND month = 7 AND day = 29
);








-- Create a table of suspects
CREATE TABLE suspects (
    name TEXT
);
--PARKING LOT
INSERT INTO suspects (name)
SELECT DISTINCT name FROM people
WHERE people.license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25
);


--CALLER
INSERT INTO suspects (name)
SELECT DISTINCT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

--ATM MACHINE
INSERT INTO suspects (name)
SELECT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";

--PASSENGER
INSERT INTO suspects (name)
SELECT DISTINCT name FROM people
WHERE passport_number IN (

    SELECT passport_number FROM passengers
    JOIN flights ON flights.id = passengers.flight_id
    WHERE flights.id = (
        SELECT flights.id FROM airports
        JOIN flights ON airports.id = flights.destination_airport_id
        WHERE airports.id IN (
        SELECT destination_airport_id FROM flights
        WHERE year = 2021 AND month = 7 AND day = 29
        ORDER BY hour LIMIT 1
        ) AND year = 2021 AND month = 7 AND day = 29
    )
    AND year = 2021 AND month = 7 AND day = 29
);

SELECT count(name), name FROM suspects
GROUP BY name
HAVING COUNT(name) >= 4;
-- potential final suspects Bruce
--appeared getting the parking lot, ATM machine, Caller and airplane passenger seat
