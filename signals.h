#define MAX_HEIGHT 75000

//Table 2.1 Caractere de elevador
#define SEND_SIGNAL_LEFT_ELEVATOR 'e'
#define SEND_SIGNAL_CENTER_ELEVATOR 'c'
#define SEND_SIGNAL_RIGHT_ELEVATOR 'd'

// Tabela 2.2 Comandos para os elevadores
#define INITIALIZE 'r'
#define OPEN_DOORS 'a'
#define CLOSE_DOORS 'f'
#define UP 's'
#define DOWN 'd'
#define STOP 'p'
#define CONSULT 'x'
#define TURN_ON_BUTTON_LIGHT 'L'
#define TURN_OFF_BUTTON_LIGHT 'D'

//Tabela 2.3 Botões internos
#define FLOOR_0 'a'
#define FLOOR_1 'b'
#define FLOOR_2 'c'
#define FLOOR_3 'd'
#define FLOOR_4 'e'
#define FLOOR_5 'f'
#define FLOOR_6 'g'
#define FLOOR_7 'h'
#define FLOOR_8 'i'
#define FLOOR_9 'j'
#define FLOOR_10 'k'
#define FLOOR_11 'l'
#define FLOOR_12 'm'
#define FLOOR_13 'n'
#define FLOOR_14 'o'
#define FLOOR_15 'p'

//Tabela 2.4.2 Eventos na simulação
#define SIGNAL_0_ELEVATOR '0'
#define SIGNAL_1_ELEVATOR '1'
#define SIGNAL_2_ELEVATOR '2'
#define SIGNAL_3_ELEVATOR '3'
#define SIGNAL_DOORS_OPEN 'A'
#define SIGNAL_DOORS_CLOSED 'F'

// ??
#define READY 'r'
#define BUSY 'b'

#define END_COMMAND '\r'

