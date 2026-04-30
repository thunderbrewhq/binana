#ifndef CLIENT_GAME_CLIENT_COMMANDS_H
#define CLIENT_GAME_CLIENT_COMMANDS_H

DECLARE_STRUCT(GameClientCommands);
DECLARE_STRUCT(GameClientCommands__v_table);

#define INTERFACE GameClientCommands
struct GameClientCommands__v_table {
    E_METHOD(void, Install);
    E_METHOD(void, Uninstall);
};
#undef INTERFACE

struct GameClientCommands {
    GameClientCommands__v_table* v_table;
};

#endif
