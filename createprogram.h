#ifndef _CREATEPROGRAM_
#define _CREATEPROGRAM_

class CreateProgram{

    public:
    unsigned int createDrawProgram();
    unsigned int createDetectingProgram();
    unsigned int createTransformingProgram();
    unsigned int checkProgramLinkStatus(unsigned int handle);
};
#endif