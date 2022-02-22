#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "helper.h"
#include "Program.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "BufferDescriptor.h"
#include "Texture.h"

#include "gtc/matrix_transform.hpp"
#include "Window/Window.h"
#include "Application.h"

#include <thread>

int main() {


    {
        Application app1;
        app1.run();
    }



    glfwTerminate();

    std::cout << "Exited successfully" << std::endl;

    return 0;
}
