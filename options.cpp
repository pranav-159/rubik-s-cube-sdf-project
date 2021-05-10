#include"opengl.h"

//this complete cpp files is to just generate the transformation_matrix

glm::mat4 options_t::transform_matrix{
    1.0f,0.0f,0.0f,0.0f,
    0.0f,1.0f,0.0f,0.0f,
    0.0f,0.0f,1.0f,0.0f,
    0.0f,0.0f,0.0f,1.0f
    };

void options_t::pass_transform_matrix(){
    unsigned transform_matrix_loc = glGetUniformLocation(shader_t::get_shader_program_id(),"transform_matrix");
    glUniformMatrix4fv(transform_matrix_loc,1,GL_FALSE, glm::value_ptr(transform_matrix));
} 


// zoom in and zoom out function
void options_t::scroll_callback(GLFWwindow *window, double xoffset , double yoffset){
    if(yoffset<0){
        transform_matrix = glm::scale(transform_matrix,glm::vec3(0.75f,0.75f,0.75f));
    }
    else transform_matrix = glm::scale(transform_matrix,glm::vec3(1.25f,1.25f,1.25f));
    pass_transform_matrix();
    
}

//contains functions to rotate the cube 
void options_t::rotate_callback(GLFWwindow *window, unsigned normal_key, int modifier_key){
    if(modifier_key == 0 )
    {
        switch (normal_key)
        {
        case 'h':
        transform_matrix = glm::rotate(transform_matrix,(float)(PI*0.25),glm::vec3(0.0f,1.0f,0.0f));
            break;
        case 'l':
        transform_matrix = glm::rotate(transform_matrix,(float)(-PI*0.25),glm::vec3(0.0f,1.0f,0.0f));
        default:
            break;
        }
        
        pass_transform_matrix();
    }
    
}


/**
 *  view_function();
 * 
 *  should display all the faces of cube side by side
 *  
 *  
 **/