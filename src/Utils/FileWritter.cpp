#include "../../inc/Utils/FileWritter.h" 

FileWritter::~FileWritter()
{
    this->resultsFile.flush();
    this->resultsFile.close();
    this->resultsPath.clear();
}

void FileWritter::openFile(std::string filePath_)
{
    this->resultsPath = filePath_;
    this->resultsFile.open(resultsPath.c_str(), std::fstream::out | std::fstream::trunc);

    if(!this->resultsFile.good())
    {
        std::cout << "Something went wrong with file\n";
        return;
    } 

    this->resultsFile.clear();
    this->resultsFile.seekp(0);
}

void FileWritter::writeIntoFile(std::string algorithm_, size_t instanceSize_, double time_)
{
    this->resultsFile << algorithm_ << ";" << instanceSize_ << ";" << time_ << "\n";
    this->resultsFile.flush();
}

void FileWritter::writeGreedyIntoFile(std::string fileName_, double best_, double worst_, double avg_, double std_)
{
    this->resultsFile << fileName_ << ";" << best_ << ";" << worst_ << ";" << avg_ << ";" << std_ << "\n";
    this->resultsFile.flush();
}

void FileWritter::writeSAIntoFile(std::string fileName_, double stopTime_, double coolingRatio_, double time_, size_t saValue_, size_t bestKnownValue_)
{
    this->resultsFile << fileName_ << ";" << stopTime_ << ";" << coolingRatio_ << ";" << time_ << ";" << saValue_<< ";" << bestKnownValue_ << "\n";
    this->resultsFile.flush();
}

void FileWritter::writeTBSIntoFile(std::string fileName_, double stopTime_, NeighbourType type_, double time_, size_t tsValue_, size_t bestKnownValue_)
{
    this->resultsFile << fileName_ << ";" << stopTime_ << ";" << EnumCaster::castToString(type_) << ";" << time_ << ";" << tsValue_<< ";" << bestKnownValue_ << "\n";
    this->resultsFile.flush();
}

void FileWritter::writeGAIntoFile(std::string fileName_, MutationType mutType_, double mutProp_, CrossoverType crossType_, double crossProp_, double time_, float gaValue_)
{
    this->resultsFile << fileName_ << ";" << EnumCaster::castToString(mutType_) << ";" 
        << mutProp_ << ";" << EnumCaster::castToString(crossType_) << ";" << crossProp_ << ";" 
        << time_ << ";" << gaValue_ << "\n";
    
    this->resultsFile.flush();
}

void FileWritter::writeextendedGAIntoFile(std::string fileName_, MutationType mutType_, double mutProp_, CrossoverType crossType_, double crossProp_, float gaValue_, size_t populationSize, double stopTime, char selectionType, int tournamentSize, char initializationType){

    this->resultsFile << fileName_ << ";" << EnumCaster::castToString(mutType_) << ";"
        << mutProp_ << ";" << EnumCaster::castToString(crossType_) << ";" << crossProp_ << ";"
    << populationSize << ";" << stopTime << ";" << selectionType << ";" << tournamentSize << ";" << initializationType << ";" << gaValue_ << "\n";

    this->resultsFile.flush();
}

void FileWritter::writeErrorsRelativeToPopulation(std::string fileName_, size_t populationSize_, MutationType mutType_, CrossoverType crossType_, double time_, float gaValue_)
{
        this->resultsFile << fileName_ << ";" << populationSize_ << ";" << EnumCaster::castToString(mutType_) << ";" 
        << EnumCaster::castToString(crossType_) << ";"  << time_ << ";" << gaValue_ << "\n";
    
    this->resultsFile.flush();
}
