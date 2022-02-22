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

int main() {


    {
        Application app;
        app.run();
    }



    glfwTerminate();

    return 0;
}
