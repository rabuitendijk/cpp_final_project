##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=cpp_final_project
ConfigurationName      :=Debug
WorkspacePath          := "/home/rabuitendijk/Documents"
ProjectPath            := "/home/rabuitendijk/Documents/Projects_Cpp/cpp_final_project"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=rabuitendijk
Date                   :=12/05/17
CodeLitePath           :="/home/rabuitendijk/.codelite"
LinkerName             :=/usr/bin/x86_64-linux-gnu-g++
SharedObjectLinkerName :=/usr/bin/x86_64-linux-gnu-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="cpp_final_project.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/x86_64-linux-gnu-ar rcu
CXX      := /usr/bin/x86_64-linux-gnu-g++
CC       := /usr/bin/x86_64-linux-gnu-gcc
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/x86_64-linux-gnu-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_main.cxx$(ObjectSuffix) $(IntermediateDirectory)/src_Test.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Heat1D.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main.cxx$(ObjectSuffix): src/main.cxx $(IntermediateDirectory)/src_main.cxx$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rabuitendijk/Documents/Projects_Cpp/cpp_final_project/src/main.cxx" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cxx$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cxx$(DependSuffix): src/main.cxx
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cxx$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cxx$(DependSuffix) -MM "src/main.cxx"

$(IntermediateDirectory)/src_main.cxx$(PreprocessSuffix): src/main.cxx
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cxx$(PreprocessSuffix) "src/main.cxx"

$(IntermediateDirectory)/src_Test.cpp$(ObjectSuffix): src/Test.cpp $(IntermediateDirectory)/src_Test.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rabuitendijk/Documents/Projects_Cpp/cpp_final_project/src/Test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Test.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Test.cpp$(DependSuffix): src/Test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Test.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Test.cpp$(DependSuffix) -MM "src/Test.cpp"

$(IntermediateDirectory)/src_Test.cpp$(PreprocessSuffix): src/Test.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Test.cpp$(PreprocessSuffix) "src/Test.cpp"

$(IntermediateDirectory)/src_Heat1D.cpp$(ObjectSuffix): src/Heat1D.cpp $(IntermediateDirectory)/src_Heat1D.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rabuitendijk/Documents/Projects_Cpp/cpp_final_project/src/Heat1D.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Heat1D.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Heat1D.cpp$(DependSuffix): src/Heat1D.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Heat1D.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Heat1D.cpp$(DependSuffix) -MM "src/Heat1D.cpp"

$(IntermediateDirectory)/src_Heat1D.cpp$(PreprocessSuffix): src/Heat1D.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Heat1D.cpp$(PreprocessSuffix) "src/Heat1D.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


