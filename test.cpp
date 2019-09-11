//
// Created by admin on 2019-09-10.
//

#include "log.h"

int main() {
    LOG_DEBUG << "LOG_DEBUG" << 1;
    LOG_INFO << "LOG_INFO" << 1;
    LOG_WARN << "LOG_WARN" << 1;
    LOG_ERROR << "LOG_ERROR" << 1;
    LOG_FATAL << "LOG_FATAL" << 1;
    LOG_SPCL << "LOG_SPCL" << 1;

//    {
//        logger::getInstance()->initLogger("./logs/", "testLog", logger::L_INFO);
//
//        int i = 0;
//        while (i++ < 1000000) {
//            LOG_DEBUG << "LOG_DEBUG" << 2;
//            LOG_INFO << "LOG_INFO" << 2;
//            LOG_WARN << "LOG_WARN" << 2;
//            LOG_ERROR << "LOG_ERROR" << 2;
//            LOG_FATAL << "LOG_FATAL" << 2;
//            LOG_SPCL << "LOG_SPCL" << 2;
//            sleep(5);
//        }
//    }

    {
        logger::getInstance()->initLogger("./logs/", "testLog", logger::L_INFO, 3);

        int i = 0;
        while( i++ < 1000000){
            LOG_DEBUG << "LOG_DEBUG" << 2;
            LOG_INFO << "LOG_INFO" << 2;
            LOG_WARN << "LOG_WARN" << 2;
            LOG_ERROR << "LOG_ERROR" << 2;
            LOG_FATAL << "LOG_FATAL" << 2;
            LOG_SPCL << "LOG_SPCL" << 2;
            sleep(5);
        }
    }

    logger::getInstance()->initLogger("./logs/", "testLog", logger::L_INFO);

    LOG_DEBUG_IMM("LOG_DEBUG" + std::to_string(1));
    LOG_INFO_IMM("LOG_INFO" + std::to_string(1));
    LOG_WARN_IMM("LOG_WARN" + std::to_string(1));
    LOG_ERROR_IMM("LOG_ERROR" + std::to_string(1));
    LOG_SPCL_IMM("LOG_SPCL" + std::to_string(1));

    auto loggerHolder = logger::getInstance();
    if (loggerHolder->debug) LOG_DEBUG << "LOG_DEBUG" << 1;
    if (loggerHolder->info) LOG_INFO << "LOG_INFO" << 1;
    if (loggerHolder->warn) LOG_WARN << "LOG_WARN" << 1;
    if (loggerHolder->error) LOG_ERROR << "LOG_ERROR" << 1;
    LOG_FATAL << "LOG_FATAL";
    LOG_SPCL << "LOG_SPCL";


}