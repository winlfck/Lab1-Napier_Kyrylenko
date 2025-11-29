/* ТРАНЗАКЦІЯ 1 */
START TRANSACTION;
LOCK TABLE employer IN EXCLUSIVE MODE;
SELECT * FROM employer WHERE e_id = 1;
UPDATE employer SET name = 'Kyrylenko_T1' WHERE e_id = 1;
SELECT * FROM employer WHERE e_id = 1;
COMMIT;

/* ТРАНЗАКЦІЯ 2 */
START TRANSACTION;
LOCK TABLE employer IN EXCLUSIVE MODE;
SELECT * FROM employer WHERE e_id = 1;
UPDATE employer SET name = 'Kyrylenko_T2' WHERE e_id = 1;
SELECT * FROM employer WHERE e_id = 1;
COMMIT;
O

