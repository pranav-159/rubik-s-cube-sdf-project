#include"opengl.h"
#include <fstream>
#include <sstream>


void FileToString(const char* FileName,std::string& ShaderCode)
{
    std::ifstream ShaderFile;
    std::stringstream ShaderStream;
    ShaderFile.exceptions(std::fstream::failbit|std::fstream::badbit);
    try{
        ShaderFile.open(FileName);
        ShaderStream<<ShaderFile.rdbuf();   
        ShaderFile.close();  
    }
    catch(std::ifstream::failure e)
    {
        std::cout<<"ERROR::SHADER::FILE_NOT_SUCESSFULLY_READ"<<std::endl;
    }
    ShaderCode=ShaderStream.str();
}  
/**
 *  This uses a singleton design pattern because there should be only one shader creator in 
 *  the program  
 **/


    unsigned shader_t :: shader_program_id;

    shader_t::shader_t(){shader_program_id = 0;}

    void shader_t::set_shaders(){


    std::string VShaderCode,GShaderCode,FShaderCode;

    FileToString("vertexShaderTile.txt",VShaderCode);
    FileToString("GeometryShaderTile.txt",GShaderCode);
    FileToString("FragmentShaderTile.txt",FShaderCode);

    const char *vertexShaderSource   =VShaderCode.c_str();
    const char *geometryShaderSource =GShaderCode.c_str();
    const char *fragmentShaderSource =FShaderCode.c_str();

    // build and compile our shader program
    // vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        
    }
    //geometric shader
    unsigned int geometryShader= glCreateShader(GL_GEOMETRY_SHADER);
    glShaderSource(geometryShader,1,&geometryShaderSource,NULL);
    glCompileShader(geometryShader);
    glGetShaderiv(geometryShader,GL_COMPILE_STATUS,&success);
    if(!success)
    {
        glGetShaderInfoLog(geometryShader,512,NULL,infoLog);
        std::cout << "ERROR::SHADER::GEOMETRY::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        
    }
    // link shaders
    shader_program_id = glCreateProgram();
    glAttachShader(shader_program_id, vertexShader);
    glAttachShader(shader_program_id,geometryShader);
    glAttachShader(shader_program_id, fragmentShader);
    glLinkProgram(shader_program_id);
    // check for linking errors
    glGetProgramiv(shader_program_id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program_id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        
    }
    glDeleteShader(vertexShader);
    glDeleteShader(geometryShader);
    glDeleteShader(fragmentShader);
}

    
   unsigned shader_t:: get_shader_program_id(){
        set_shaders();
        return shader_program_id;
    }
    





    