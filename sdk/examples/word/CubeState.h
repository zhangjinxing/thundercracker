#ifndef CUBESTATE_H
#define CUBESTATE_H

enum CubeStateIndex
{
    CubeStateIndex_Title,
    CubeStateIndex_TitleExit,
    CubeStateIndex_NotWordScored,
    CubeStateIndex_NewWordScored,
    CubeStateIndex_OldWordScored,
    CubeStateIndex_StartOfRoundScored,
    CubeStateIndex_EndOfRoundScored,
    CubeStateIndex_ShuffleScored,

    CubeStateIndex_NumStates
};

#endif // CUBESTATE_H
