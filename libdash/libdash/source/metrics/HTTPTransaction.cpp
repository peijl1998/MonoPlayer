/*
 * HTTPTransaction.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "HTTPTransaction.h"

using namespace dash::metrics;

HTTPTransaction::HTTPTransaction () :
                 tcpId           (0),
                 type            (dash::metrics::Other),
                 responseCode    (0),
                 interval        (0),
                 url             (""),
                 actualUrl       (""),
                 range           (""),
                 tRequest        (0),
                 tResponse       (0),
                 tFinish         (0),
                 recvBytes       (0),
                 isValid         (false),
                 httpHeader      ("")
{
}
HTTPTransaction::~HTTPTransaction()
{
    for (size_t i = 0; i < trace.size(); i++)
        delete trace.at(i);
}

uint32_t                                        HTTPTransaction::TCPId                      () const
{
    return this->tcpId;
}
void                                            HTTPTransaction::SetTCPId                   (uint32_t tcpId)
{
    this->tcpId = tcpId;
}
HTTPTransactionType                             HTTPTransaction::Type                       () const
{
    return this->type;
}
void                                            HTTPTransaction::SetType                    (HTTPTransactionType type)
{
    this->type = type;
}
const std::string&                              HTTPTransaction::OriginalUrl                () const
{
    return this->url;
}
void                                            HTTPTransaction::SetOriginalUrl             (const std::string& origUrl)
{
    this->url = origUrl;
}
const std::string&                              HTTPTransaction::ActualUrl                  () const
{
    return this->actualUrl;
}
void                                            HTTPTransaction::SetActualUrl               (const std::string& actUrl)
{
    this->actualUrl = actUrl;
}
const std::string&                              HTTPTransaction::Range                      () const
{
    return this->range;
}
void                                            HTTPTransaction::SetRange                   (const std::string& range)
{
    this->range = range;
}
uint64_t                                        HTTPTransaction::RequestSentTime            () const
{
    return this->tRequest;
}
void                                            HTTPTransaction::SetRequestSentTime         (uint64_t tRequest)
{
    this->tRequest = tRequest;
}
uint64_t                                        HTTPTransaction::ResponseReceivedTime       () const
{
    return this->tResponse;
}
void                                            HTTPTransaction::SetResponseReceivedTime    (uint64_t tResponse)
{
    this->tResponse = tResponse;
}
uint64_t                                        HTTPTransaction::DownloadFinishedTime       () const
{
    return this->tFinish;
}
void                                            HTTPTransaction::SetDownloadFinishedTime    (uint64_t tFinish)
{
    this->tFinish = tFinish;
    this->isValid = true;
}
uint64_t                                        HTTPTransaction::ReceivedBytes              () const
{
    return this->recvBytes;
}
void                                            HTTPTransaction::AddReceivedBytes           (uint64_t bytes)
{
    this->recvBytes += bytes;
}
uint16_t                                        HTTPTransaction::ResponseCode               () const
{
    return this->responseCode;
}
void                                            HTTPTransaction::SetResponseCode            (uint16_t respCode)
{
    this->responseCode = respCode;
}
uint64_t                                        HTTPTransaction::Interval                   () const
{
    return this->interval;
}
void                                            HTTPTransaction::SetInterval                (uint64_t interval)
{
    this->interval = interval;
}
const std::vector<IThroughputMeasurement *>&    HTTPTransaction::ThroughputTrace            () const
{
    return (std::vector<IThroughputMeasurement *> &) this->trace;
}
void                                            HTTPTransaction::AddThroughputMeasurement   (ThroughputMeasurement *throuputEntry)
{
    this->trace.push_back(throuputEntry);
}
const std::string&                              HTTPTransaction::HTTPHeader                 () const
{
    return this->httpHeader;
}
void                                            HTTPTransaction::AddHTTPHeaderLine          (std::string headerLine)
{
    this->httpHeader.append(headerLine);
}
bool                                            HTTPTransaction::Valid                      () const
{
    return this->isValid;
}
