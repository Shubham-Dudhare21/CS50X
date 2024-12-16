-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Check the schema of all the data present in the database
.schema

-- Querys to catch the thief
    -- To check if the words like CS50 or DUCK exist in the database
    -- And if its there note where the crime took place
    SELECT * FROM crime_scene_reports WHERE description LIKE '%CS50%';
    SELECT * FROM crime_scene_reports WHERE description LIKE '%Duck%';
    -- This is the result of query     id - 295, date - 2023-07-28  Time - 10:15am  place - Humphrey Street | Interviews were conducted today with three witnesses
    -- CLUE - Humphrey Street and each interview transcript mention bakery.


    -- NEXT query for interviews table
    SELECT * FROM interviews WHERE transcript LIKE '%bakery%' AND day = 28;
    -- CLUE 1 - car no. plate must be in bakerys_security_logs according to Ruth
    -- CLUE 2 - thief withdraw money from ATM at Leggett Street before thieft According to Eugene
    -- CLUE 3 - thief called someone for less than a minuite after thieft ACCORDING TO Raymond
    -- *CLUE 4 - the other person on phone was told to book a flight ticket for thief to leave the town TOMORROW

    -- NEXT query is for checking the cars exited from the bakery on the day
    SELECT * FROM bakery_security_logs WHERE day = 28 AND activity = 'exit' AND hour = 10 AND 25 >= minute AND minute >= 15;
    -- NEXT query is for list of people who withdraw money at the atm
    SELECT * FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw');
    -- NEXT query is for getting the calls data on the day
    SELECT * FROM phone_calls WHERE day = 28 AND duration < 60;

    -- NEXT query is to check if all the data collected have any person in common
    SELECT * FROM people WHERE phone_number IN
    (SELECT caller FROM phone_calls WHERE day = 28 AND duration < 60) AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND activity = 'exit' AND hour = 10 AND minute >= 15);
    -- NEXT is to check if the name from above query ever made transaction on theift day
    SELECT * FROM people WHERE phone_number IN
    (SELECT caller FROM phone_calls WHERE day = 28 AND duration < 60) AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND activity = 'exit' AND hour = 10 AND minute >= 15) AND id IN
    (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'));
    -- WITH the above we got 3 names for the suspects Taylor, Diana and Bruce

    -- The following query is to get the flight which was booked for leaving fiftyville
    -- Fiftyville airport id is 8 - SELECT * FROM airports;
    -- THE earliest flight for the 29 july is hour - 8
    SELECT * FROM flights WHERE origin_airport_id = 8 AND day = 29 AND ORDER BY hour LIMIT 1;
    -- it gave the flight_id - 36

    -- now to check who are the people booked for the flight from suspects
    SELECT * FROM people WHERE passport_number IN
    (SELECT passport_number FROM passengers WHERE flight_id IS 36) AND id IN (SELECT id FROM people WHERE phone_number IN
    (SELECT caller FROM phone_calls WHERE day = 28 AND duration < 60) AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND activity = 'exit' AND hour = 10 AND minute >= 15) AND id IN
    (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw')));

