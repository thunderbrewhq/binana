#ifndef CLIENT_GAME_CLIENT_COMMANDS_H
#define CLIENT_GAME_CLIENT_COMMANDS_H

DECLARE_STRUCT(GameClientCommands);
DECLARE_STRUCT(GameClientCommands__v_table);

struct GameClientCommands__v_table {
    E_METHOD(GameClientCommands, void, Install);
    E_METHOD(GameClientCommands, void, Uninstall);
    // void* Install;
    // void* Uninstall;
};

struct GameClientCommands {
    GameClientCommands__v_table* v_table;
};

#endif
