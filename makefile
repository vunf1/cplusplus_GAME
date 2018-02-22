all:
	reset
	@echo  "                 .-'''-.\n                / .===. \ \n                \/ O O \/ \n                ( \___/ )\n  __________ooo__\_____/_______________ \n /                                     \ \n|    Developed with \033[0;31mLove\033[0m and \033[0;33mfree time\033[0m  |\n|              Group F3                 |\n|            \033[92mCompiling...\033[0m               |\n|         Remember if an error          |\n|   appear look frist compile error     |\n|        because c++ is static          |\n|            1st on top fail?           |\n|      next will fail consequently      |\n| if they are connected with each other |\n \________________________ooo__________/\n                 |  |  |\n                 |_ | _|\n                 |  |  |\n                 |__|__|\n                 /-'Y'-\ \n                (__/ \__)\n"
	
	g++ -std=c++14 main.cpp -lsqlite3 -lncurses -o game && ./game
 
.SILENT:

.IGNORE:
