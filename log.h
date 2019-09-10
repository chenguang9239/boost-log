//
// Created by admin on 2018/9/11.
//
#include <unistd.h>
#include <boost/log/sinks.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>

#ifndef DOC_FEATURE_LOG_H
#define DOC_FEATURE_LOG_H

class logger {
public:
    enum LEVEL {
        L_DEBUG,
        L_INFO,
        L_WARN,
        L_ERROR,
        L_FATAL,
        L_SPCL
    };

    typedef boost::log::sinks::synchronous_sink<boost::log::sinks::text_file_backend> file_sink_t;
    typedef boost::log::sinks::synchronous_sink<boost::log::sinks::text_ostream_backend> basic_sink_t;

    static bool debug;
    static bool info;
    static bool warn;
    static bool error;
    static bool fatal;
    static bool isInitialized;

    static boost::shared_ptr<basic_sink_t> defaultSinkPtr;
    static boost::shared_ptr<file_sink_t> fileSinkPtr;
    static boost::log::sources::severity_logger<LEVEL> lg;
//    static boost::log::sources::severity_logger<boost::log::trivial::severity_level> lg;

    static void flush();

    static void stopDefaultLogging();

    static boost::shared_ptr<basic_sink_t> init();

    static void initLogger(const std::string &logPath, const std::string &logName, enum LEVEL level);

    static std::string innerPutTime(struct tm *t);

    static std::string padTime(const std::string &time);

    static std::string TimeStampToLocalTime(uint64_t timestamp);
};

#define LOG_SPCL BOOST_LOG_SEV(logger::lg,logger::L_SPCL) << "[" << __FILE__ << ":" << __LINE__ << "]: "
#define LOG_DEBUG BOOST_LOG_SEV(logger::lg,logger::L_DEBUG) << "[" << __FILE__<< ":" << __LINE__<< "]: "
#define LOG_INFO BOOST_LOG_SEV(logger::lg,logger::L_INFO) << "[" << __FILE__ << ":" << __LINE__ << "]: "
#define LOG_WARN BOOST_LOG_SEV(logger::lg,logger::L_WARN) << "[" << __FILE__ << ":" << __LINE__ << "]: "
#define LOG_ERROR BOOST_LOG_SEV(logger::lg,logger::L_ERROR) << "[" << __FILE__ << ":" << __LINE__ << "]: "
#define LOG_FATAL BOOST_LOG_SEV(logger::lg,logger::L_FATAL) << "[" << __FILE__ << ":" << __LINE__ <<  "]: "

#define LOG_SPCL_IMM(data) {LOG_SPCL << (data);logger::flush();}
#define LOG_DEBUG_IMM(data) {if(logger::debug) {LOG_DEBUG << (data);logger::flush();}}
#define LOG_INFO_IMM(data) {if(logger::info) {LOG_INFO << (data);logger::flush();}}
#define LOG_WARN_IMM(data) {if(logger::warn) {LOG_WARN << (data);logger::flush();}}
#define LOG_ERROR_IMM(data) {if(logger::error) {LOG_ERROR << (data);logger::flush();}}
#define LOG_FATAL_IMM(data) {LOG_FATAL << (data);logger::flush();}

#endif //DOC_FEATURE_LOG_H
