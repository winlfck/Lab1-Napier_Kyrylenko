/* ТРАНЗАКЦІЯ 1 */
START TRANSACTION;
UPDATE employer SET salary = 1000 WHERE e_id = 1;
/* Тут T1 блокує рядок 1 */
UPDATE employer SET salary = 1000 WHERE e_id = 2;
/* Тут T1 спробує заблокувати рядок 2 і буде чекати */
COMMIT;

/* ТРАНЗАКЦІЯ 2 */
START TRANSACTION;
UPDATE employer SET salary = 2000 WHERE e_id = 2;
/* Тут T2 блокує рядок 2 */
UPDATE employer SET salary = 2000 WHERE e_id = 1;
/* Тут T2 спробує заблокувати рядок 1 -> DEADLOCK */
COMMIT;
