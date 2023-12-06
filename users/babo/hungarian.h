#pragma once

enum unicode_names {
    A_AC,
    E_AC,
    I_AC,
    O_AC,
    O_DA,
    O_DI,
    U_AC,
    U_DA,
    U_DI,
    a_AC,
    e_AC,
    i_AC,
    o_AC,
    o_DA,
    o_DI,
    u_AC,
    u_DA,
    u_DI,
};

#define AAC XP(a_AC, A_AC)
#define EAC XP(e_AC, E_AC)
#define IAC XP(i_AC, I_AC)
#define OAC XP(o_AC, O_AC)
#define ODA XP(o_DA, O_DA)
#define ODI XP(o_DI, O_DI)
#define UAC XP(u_AC, U_AC)
#define UDA XP(u_DA, U_DA)
#define UDI XP(u_DI, U_DI)
