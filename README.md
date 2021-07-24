# MonoPlayer
A Dash Player based on QT5 &amp; libdash.



Compared to [libdash-sample player](https://github.com/bitmovin/libdash), MonoPlayer provides features as follows.

- **Throghput Monitoring**: MonoPlayer could monitor throughput of downloaded segments via recording begin/finish timestamp and segment size when libcurl is working.
  
- **Second-based Buffer**: As we all know, many classic abr like BBA-0 use buffer level as key indicator to switch bitrate. However, among these algorithms, buffer often need to be based on second unit ranther than KB which is used in original `libdash-sample-player`. Monoplayer firstly caches each segment's duration according to MPD file and modify InternalBuffer class's pushing way, I mean, it wouldn't receive anything until its level is less than max-size like 60s. The buffer counter will plus corresponding duration based on second when a segment is pushed into buffer.
  
- **Scalable ABR Interface**: Now Monoplayer has support SimpleThroughputRule, i.e. selecting bitrate only according to throughput value. But you can integrate your algorithm easily. You just need provide network indicator(throughput, buffer level, etc.) to DASHMetric class and add your rule like `libdashframework/Adaptation/SimpleThroughputLogic.cpp`. 
  
- **WEBM SegmentBase Support**: As webm official wiki saying, webm file should be non-chunked and non-muxed when streaming in DASH. That means you can only use segmentbase url indexing. So the extra work of index parsing from webm header is need. Monoplayer has supported it:)  In details, it fetchs all cuepoint from webm header and reconstruct them into segment class which means it can reuse the logic of segmentlist.





Showcase (the red boxes indicates the metric and abr change.)

![image-20210724191648915](/Users/peijialiang/Library/Application Support/typora-user-images/image-20210724191648915.png)





Please refer to [libdash](https://github.com/bitmovin/libdash) for **Build** details.
