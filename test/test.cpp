//
// Created by admin on 2019-09-10.
//

#include "log.h"
#include <stdio.h>

#include <iostream>

#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <chrono>
#include <iomanip>

//BOOST_LOG_ATTRIBUTE_KEYWORD(a_severity, "Severity", logger::LEVEL)
//BOOST_LOG_ATTRIBUTE_KEYWORD(a_channel, "Channel", std::string)

//void test() {
//    std::string LA = "LOGA";
//    std::string LB = "LOGB";
//    boost::shared_ptr<boost::log::sinks::synchronous_sink<boost::log::sinks::text_file_backend>> fileSinkPtr1 =
//            boost::log::add_file_log(
//                    boost::log::keywords::file_name = "A.log",
//                    boost::log::keywords::filter = a_channel == LA);
//
//    boost::shared_ptr<boost::log::sinks::synchronous_sink<boost::log::sinks::text_file_backend>> fileSinkPtr2 =
//            boost::log::add_file_log(
//                    boost::log::keywords::file_name = "B.log",
//                    boost::log::keywords::filter = a_channel == LB);
//
//    fileSinkPtr1->set_filter(a_channel == LA && a_severity >= logger::L_DEBUG);
//    fileSinkPtr2->set_filter(a_channel == LB && a_severity >= logger::L_DEBUG);
//
//    typedef boost::log::sources::severity_channel_logger<logger::LEVEL, std::string> logger_type;
//
//    logger_type lg_a(boost::log::keywords::channel = "A");
//
//    logger_type lg_b(boost::log::keywords::channel = "B");
//
//    lg_a = boost::log::sources::severity_channel_logger<logger::LEVEL, std::string>(
//            boost::log::keywords::channel = LA);
//
//    lg_b = boost::log::sources::severity_channel_logger<logger::LEVEL, std::string>(
//            boost::log::keywords::channel = LB);
//
//    BOOST_LOG_SEV(lg_a, logger::L_SPCL) << "Hello, A.log!";
//    BOOST_LOG_SEV(lg_b, logger::L_SPCL) << "Hello, B.log!";
//}

int main() {
    {
        logger *logger1 = logger::builder();
        printf("logger1: %p\n", logger1);

        logger1->initLogger("./logs/", "log1", logger::L_DEBUG, 3, std::string("LOG1"));
        std::cout << "init logger1 ok" << std::endl;

        logger *logger2 = logger::builder();
        printf("logger2: %p\n", logger2);

        logger2->initLogger("./logs/", "log2", logger::L_DEBUG, 3, std::string("LOG2"));
        std::cout << "init logger2 ok" << std::endl;

        std::string LA = "A1";
        std::string LB = "B1";
        std::string LC = "A1";
        std::string LD = "B1";
        std::string LE = "A1";
        std::string LF = "B1";

#define LOG1_SPCL BOOST_LOG_SEV(logger1->lg,logger::L_SPCL) << "[" << __FILE__ << ":" << __LINE__ << "]: "
#define LOG1_DEBUG BOOST_LOG_SEV(logger1->lg,logger::L_DEBUG) << "[" << __FILE__<< ":" << __LINE__<< "]: "
#define LOG1_INFO BOOST_LOG_SEV(logger1->lg,logger::L_INFO) << "[" << __FILE__ << ":" << __LINE__ << "]: "
#define LOG1_WARN BOOST_LOG_SEV(logger1->lg,logger::L_WARN) << "[" << __FILE__ << ":" << __LINE__ << "]: "
#define LOG1_ERROR BOOST_LOG_SEV(logger1->lg,logger::L_ERROR) << "[" << __FILE__ << ":" << __LINE__ << "]: "
#define LOG1_FATAL BOOST_LOG_SEV(logger1->lg,logger::L_FATAL) << "[" << __FILE__ << ":" << __LINE__ <<  "]: "

#define LOG1_SPCL_IMM(data) {LOG1_SPCL << (data);logger1->flush();}
#define LOG1_DEBUG_IMM(data) {if(logger1->debug) {LOG1_DEBUG << (data);logger1->flush();}}
#define LOG1_INFO_IMM(data) {if(logger1->info) {LOG1_INFO << (data);logger1->flush();}}
#define LOG1_WARN_IMM(data) {if(logger1->warn) {LOG1_WARN << (data);logger1->flush();}}
#define LOG1_ERROR_IMM(data) {if(logger1->error) {LOG1_ERROR << (data);logger1->flush();}}
#define LOG1_FATAL_IMM(data) {LOG1_FATAL << (data);logger1->flush();}

#define LOG2_SPCL BOOST_LOG_SEV(logger2->lg,logger::L_SPCL) << "[" << __FILE__ << ":" << __LINE__ << "]: "
#define LOG2_DEBUG BOOST_LOG_SEV(logger2->lg,logger::L_DEBUG) << "[" << __FILE__<< ":" << __LINE__<< "]: "
#define LOG2_INFO BOOST_LOG_SEV(logger2->lg,logger::L_INFO) << "[" << __FILE__ << ":" << __LINE__ << "]: "
#define LOG2_WARN BOOST_LOG_SEV(logger2->lg,logger::L_WARN) << "[" << __FILE__ << ":" << __LINE__ << "]: "
#define LOG2_ERROR BOOST_LOG_SEV(logger2->lg,logger::L_ERROR) << "[" << __FILE__ << ":" << __LINE__ << "]: "
#define LOG2_FATAL BOOST_LOG_SEV(logger2->lg,logger::L_FATAL) << "[" << __FILE__ << ":" << __LINE__ <<  "]: "

#define LOG2_SPCL_IMM(data) {LOG2_SPCL << (data);logger2->flush();}
#define LOG2_DEBUG_IMM(data) {if(logger2->debug) {LOG2_DEBUG << (data);logger2->flush();}}
#define LOG2_INFO_IMM(data) {if(logger2->info) {LOG2_INFO << (data);logger2->flush();}}
#define LOG2_WARN_IMM(data) {if(logger2->warn) {LOG2_WARN << (data);logger2->flush();}}
#define LOG2_ERROR_IMM(data) {if(logger2->error) {LOG2_ERROR << (data);logger2->flush();}}
#define LOG2_FATAL_IMM(data) {LOG2_FATAL << (data);logger2->flush();}

        LOG1_DEBUG << "LOG_DEBUG" << 1;
        LOG1_INFO << "LOG_INFO" << 1;
        LOG1_WARN << "LOG_WARN" << 1;
        LOG1_ERROR << "LOG_ERROR" << 1;
        LOG1_FATAL << "LOG_FATAL" << 1;
        LOG1_SPCL << "LOG_SPCL" << 1;
        LOG1_DEBUG_IMM("LOG_DEBUG" + std::to_string(1));
        LOG1_INFO_IMM("LOG_INFO" + std::to_string(1));
        LOG1_WARN_IMM("LOG_WARN" + std::to_string(1));
        LOG1_ERROR_IMM("LOG_ERROR" + std::to_string(1));
        LOG1_SPCL_IMM("LOG_SPCL" + std::to_string(1));

        LOG2_DEBUG << "LOG_DEBUG" << 1;
        LOG2_INFO << "LOG_INFO" << 1;
        LOG2_WARN << "LOG_WARN" << 1;
        LOG2_ERROR << "LOG_ERROR" << 1;
        LOG2_FATAL << "LOG_FATAL" << 1;
        LOG2_SPCL << "LOG_SPCL" << 1;
        LOG2_DEBUG_IMM("LOG_DEBUG" + std::to_string(1));
        LOG2_INFO_IMM("LOG_INFO" + std::to_string(1));
        LOG2_WARN_IMM("LOG_WARN" + std::to_string(1));
        LOG2_ERROR_IMM("LOG_ERROR" + std::to_string(1));
        LOG2_SPCL_IMM("LOG_SPCL" + std::to_string(1));

        delete logger1;
        delete logger2;
    }

    sleep(3);
    return 0;


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
        while (i++ < 1000000) {
            std::cout << "print log begin..." << std::endl;
            LOG_DEBUG << "LOG_DEBUG" << 2;
            LOG_INFO << "LOG_INFO" << 2;
            LOG_WARN << "LOG_WARN" << 2;
            LOG_ERROR << "LOG_ERROR" << 2;
            LOG_FATAL << "LOG_FATAL" << 2;
            LOG_SPCL << "LOG_SPCL" << 2;
            std::cout << "print log end..." << std::endl;
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