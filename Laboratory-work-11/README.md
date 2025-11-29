## Керування процесами-транзакціями в базах даних

### 2.1 Теоретичне завдання (Варіант 8)

**Початкові транзакції:**
* T1: W[D] R[B] W[B] C1
* T2: R[A] R[B] W[A] C2
* T3: R[D] W[D] C3

#### 2.1.1 Історія (Протокол 1-го ступеня - X-блокування перед записом)
H(T1,T2,T3) = X1[D] W1[D] S2[A] R2[A] S2[B] R2[B] X2[A] W2[A] C2 U2 S1[B] R1[B] X1[B] W1[B] C1 U1 S3[D] R3[D] X3[D] W3[D] C3 U3

#### 2.1.2 Таблиця блокувань (на момент активності всіх транзакцій)
char* lock_table[][3] = {
    {"D", "X1", ""},
    {"A", "X2", ""},
    {"B", "X1", ""}
};

#### 2.1.3 Граф очікування (Deadlock)
Deadlock відсутній, оскільки транзакції захоплюють ресурси послідовно і звільняють їх.
int wait[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};

#### 2.1.4 Історія (Протокол 2-го ступеня - S-блокування перед читанням)
H(T1,T2,T3) = X1[D] W1[D] S2[A] R2[A] S2[B] R2[B] X2[A] W2[A] C2 U2 S1[B] R1[B] X1[B] W1[B] C1 U1 S3[D] R3[D] X3[D] W3[D] C3 U3


<img width="761" height="227" alt="1" src="https://github.com/user-attachments/assets/c4212fb9-954e-4a9d-899f-182dd9fccefc" />

<img width="400" height="110" alt="2" src="https://github.com/user-attachments/assets/b35e1e8c-0a4c-4fad-a983-05b7ae99528e" />

<img width="1278" height="119" alt="3" src="https://github.com/user-attachments/assets/1e1bdd2a-9509-4c78-b2d6-5bc5cd3f4676" />

<img width="775" height="111" alt="4" src="https://github.com/user-attachments/assets/c334de2b-9e56-4369-aa05-7719849531cb" />
