/*
 * HTTPTransaction.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef HTTPTRANSACTION_H_
#define HTTPTRANSACTION_H_

#include "IHTTPTransaction.h"
#include "ThroughputMeasurement.h"

namespace dash
{
    namespace metrics
    {
        class HTTPTransaction : public IHTTPTransaction
        {
            public:
                HTTPTransaction          ();
                virtual ~HTTPTransaction ();

                uint32_t                                        TCPId                   () const;
                HTTPTransactionType                             Type                    () const;
                const std::string&                              OriginalUrl             () const;
                const std::string&                              ActualUrl               () const;
                const std::string&                              Range                   () const;
                uint64_t                                        RequestSentTime         () const;
                uint64_t                                        ResponseReceivedTime    () const;
                uint64_t                                        DownloadFinishedTime    () const;
                uint64_t                                        ReceivedBytes           () const;
                uint16_t                                        ResponseCode            () const;
                uint64_t                                        Interval                () const;
                const std::vector<IThroughputMeasurement *>&    ThroughputTrace         () const;
                const std::string&                              HTTPHeader              () const;
                bool                                            Valid                 () const;

                void    SetTCPId                    (uint32_t tcpId);
                void    SetType                     (HTTPTransactionType type);
                void    SetOriginalUrl              (const std::string& origUrl);
                void    SetActualUrl                (const std::string& actUrl);
                void    SetRange                    (const std::string& range);
                void    SetRequestSentTime          (uint64_t tRequest);
                void    SetResponseReceivedTime     (uint64_t tResponse);
                void    SetDownloadFinishedTime     (uint64_t tFinish);
                void    SetResponseCode             (uint16_t respCode);
                void    SetInterval                 (uint64_t interval);
                void    AddReceivedBytes            (uint64_t bytes);
                void    AddThroughputMeasurement    (ThroughputMeasurement *throuputEntry);
                void    AddHTTPHeaderLine           (std::string headerLine);

            private:
                uint32_t                                tcpId;
                HTTPTransactionType                     type;
                std::string                             url;
                std::string                             actualUrl;
                std::string                             range;
                uint64_t                                tRequest;
                uint64_t                                tResponse;
                uint64_t                                tFinish;
                uint64_t                                recvBytes;
                uint16_t                                responseCode;
                uint64_t                                interval;
                bool                                    isValid;
                std::vector<ThroughputMeasurement *>    trace;
                std::string                             httpHeader;
        };
    }
}

#endif /* HTTPTRANSACTION_H_ */
