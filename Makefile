#Compiler and Linker
CC			:=	c++

#The Target Binary Program
TARGET		:=	ft_containers.out
DEBUGOUT	:=	debug.out

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR		:=	src/
INCDIR		:=	src/
OBJDIR		:=	obj
TARGETDIR	:=	bin
SRCEXT		:=	cpp
HDEXT		:=	hpp
OBJEXT		:=	o
CHECKDIR	:=	check
CHECKOUTDIR	:=	tmp

#Flags, Libraries and Includes
CFLAGS		:=	-Wall -Wextra -Werror -std=c++98
DEBUGFLAG	:=	-Wall -Wextra -fsanitize=address
ARG			:=	

#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------
HEADERS		:=	$(shell find $(INCDIR) -type f -name *.$(HDEXT))
SOURCES		:=	$(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS		:=	$(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

#Default Make
all: directories $(TARGETDIR)/$(TARGET)

#Remake
re:	fclean all

#Make the Directories
directories:
# directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(OBJDIR)

#Clean only Objects
clean:
	@$(RM) -rf $(OBJDIR)

#Full Clean, Objects and Binaries
fclean:	clean
	@$(RM) -rf $(TARGETDIR)

debug: directories $(OBJECTS)
	$(CC) $(DEBUGFLAG) -o $(TARGETDIR)/$(DEBUGOUT) $(OBJECTS)

leaks: directories $(OBJECTS)
	$(CC) -o $(TARGETDIR)/$(TARGET) $(OBJECTS)
	@clear
	leaks --atExit -- ./$(TARGETDIR)/$(TARGET) $(ARG)

#Link
$(TARGETDIR)/$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGETDIR)/$(TARGET) $^

#Compile
$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT) $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

#Non-File Targets
.PHONY: all re directories clean fclean debug leaks