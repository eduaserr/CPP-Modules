#!/bin/bash
# filepath: script.sh

# Verificar argumentos
if [ $# -ne 1 ]; then
	echo "Uso: $0 <NombreClase>"
	echo "Ejemplo: $0 Point"
	exit 1
fi

CLASS_NAME=$1
LOWER_CLASS=$(echo "$CLASS_NAME" | tr '[:upper:]' '[:lower:]')

echo "Creando estructura OCF para clase: $CLASS_NAME"

# Crear directorios
mkdir -p inc src

# Crear archivo header (.hpp)
cat > "inc/${CLASS_NAME}.hpp" << EOF
#ifndef ${CLASS_NAME^^}_HPP
#define ${CLASS_NAME^^}_HPP

#include <iostream>

class $CLASS_NAME {
private:

public:
	$CLASS_NAME();
	$CLASS_NAME(const $CLASS_NAME& data);
	$CLASS_NAME& operator=(const $CLASS_NAME& data);
	~$CLASS_NAME();
};

#endif
EOF

# Crear archivo fuente (.cpp)
cat > "src/${CLASS_NAME}.cpp" << EOF
#include "../inc/${CLASS_NAME}.hpp"

${CLASS_NAME}::${CLASS_NAME}(){}
${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME}& data){(void)data;}
${CLASS_NAME}& ${CLASS_NAME}::operator=(const ${CLASS_NAME}& data){(void)data;
    return (*this);}
${CLASS_NAME}::~${CLASS_NAME}(){}

EOF

# Crear main.cpp
cat > "main.cpp" << EOF
#include "inc/${CLASS_NAME}.hpp"

int main() {
	$CLASS_NAME obj;
	return 0;
}
EOF

# Crear Makefile
cat > "Makefile" << 'EOF'
NAME = CLASS_NAME_PLACEHOLDER
CC		= g++
CFLAGS	= -Wall -Wextra -Werror -g -std=c++98

SRC		= main.cpp
SRCS	= src/CLASS_NAME_PLACEHOLDER.cpp

### OBJS ###
OBJS	= $(SRC:.cpp=.o) $(SRCS:.cpp=.o)

### RULES ###
all : $(NAME)

$(NAME): $(OBJS)
	@echo "loading ..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "compiled successfully"

%.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "clearing...🧹"

fclean: clean
	@$(RM) $(NAME)
	@echo "clearing executables"

re: fclean all

.PHONY: all clean fclean re
EOF

# Reemplazar el placeholder con el nombre real de la clase
sed -i "s/CLASS_NAME_PLACEHOLDER/${CLASS_NAME}/g" Makefile

echo "✅ Estructura creada exitosamente!"
echo "📁 Archivos generados:"
echo "   - inc/${CLASS_NAME}.hpp"
echo "   - src/${CLASS_NAME}.cpp" 
echo "   - main.cpp"
echo "   - Makefile"
echo ""
echo "🔨 Para compilar: make"
echo "▶️  Para ejecutar: ./${CLASS_NAME}"