# Versão mínima do CMake
cmake_minimum_required(VERSION 3.5)

# Informações básicas do projeto.
project(Musify
        VERSION 1.0
        DESCRIPTION "Um gerenciador de músicas via linha de comando."
        HOMEPAGE_URL "https://github.com/itallocortez/Musify"
        LANGUAGES CXX)

# Incluir informações para depuração no executável
set(CMAKE_CXX_FLAGS "-g")

# Informa o diretório dos arquivos de cabeçalho
include_directories( include )

# Cria um executável a partir dos códigos fonte
add_executable( musify
                src/main.cpp
                src/musica.cpp
                src/playlist.cpp )