typedef struct contaBancaria ContaBancaria;
ContaBancaria *cria_conta(char *titular, int numero, float saldo);
void deposita(ContaBancaria *contabancaria, float saldo);
void sacar_saldo(ContaBancaria *contabancaria, float saldo);
void transfere_saldo(ContaBancaria **contabancaria, float transfere);
void ver_saldo(ContaBancaria *contabancaria);
void exclui_conta(ContaBancaria **contabancaria);