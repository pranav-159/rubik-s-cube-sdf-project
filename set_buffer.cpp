#include"opengl.h"


void set_buffer::init_buffer(){
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,3,GL_FLOAT,GL_FALSE,9*sizeof(float),(void*)(6*sizeof(float)));
    glEnableVertexAttribArray(2);
}


GLsizei set_buffer::indices_size(){return sizeof(indices);}


GLsizei data::setVertices(){
    set_buffer dataRenderd;
    unsigned choice;
    std::cout<<"Please enter 1 to get a shuffled cube and 2 to get patterns of the cube \n";
    std::cin>>choice;
    if(choice == 1){
        std::copy(shuffled,shuffled+(24*6),dataRenderd.vertices);
        std::cout<<"You have selected to solve the shuffled cube\n";
        dataRenderd.init_buffer();
        dataRenderd.indices_size();
    }
    else if(choice == 2){
        std::copy(pattern,pattern+(24*6),dataRenderd.vertices);
        std::cout<<"You have selected to solve the pattern \n";
        dataRenderd.init_buffer();
        dataRenderd.indices_size();
    }
    else{
        std::cout<<"Please enter 1 or 2 \n";
        setVertices();
    }
}

