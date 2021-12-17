#ifndef _ROS_SERVICE_TopicsAndRawTypes_h
#define _ROS_SERVICE_TopicsAndRawTypes_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosapi
{

static const char TOPICSANDRAWTYPES[] = "rosapi/TopicsAndRawTypes";

  class TopicsAndRawTypesRequest : public ros::Msg
  {
    public:

    TopicsAndRawTypesRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return TOPICSANDRAWTYPES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class TopicsAndRawTypesResponse : public ros::Msg
  {
    public:
      uint8_t topics_length;
      char* st_topics;
      char* * topics;
      uint8_t types_length;
      char* st_types;
      char* * types;
      uint8_t typedefs_full_text_length;
      char* st_typedefs_full_text;
      char* * typedefs_full_text;

    TopicsAndRawTypesResponse():
      topics_length(0), topics(NULL),
      types_length(0), types(NULL),
      typedefs_full_text_length(0), typedefs_full_text(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = topics_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < topics_length; i++){
      uint32_t length_topicsi = strlen(this->topics[i]);
      memcpy(outbuffer + offset, &length_topicsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->topics[i], length_topicsi);
      offset += length_topicsi;
      }
      *(outbuffer + offset++) = types_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < types_length; i++){
      uint32_t length_typesi = strlen(this->types[i]);
      memcpy(outbuffer + offset, &length_typesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->types[i], length_typesi);
      offset += length_typesi;
      }
      *(outbuffer + offset++) = typedefs_full_text_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < typedefs_full_text_length; i++){
      uint32_t length_typedefs_full_texti = strlen(this->typedefs_full_text[i]);
      memcpy(outbuffer + offset, &length_typedefs_full_texti, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->typedefs_full_text[i], length_typedefs_full_texti);
      offset += length_typedefs_full_texti;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t topics_lengthT = *(inbuffer + offset++);
      if(topics_lengthT > topics_length)
        this->topics = (char**)realloc(this->topics, topics_lengthT * sizeof(char*));
      offset += 3;
      topics_length = topics_lengthT;
      for( uint8_t i = 0; i < topics_length; i++){
      uint32_t length_st_topics;
      memcpy(&length_st_topics, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_topics; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_topics-1]=0;
      this->st_topics = (char *)(inbuffer + offset-1);
      offset += length_st_topics;
        memcpy( &(this->topics[i]), &(this->st_topics), sizeof(char*));
      }
      uint8_t types_lengthT = *(inbuffer + offset++);
      if(types_lengthT > types_length)
        this->types = (char**)realloc(this->types, types_lengthT * sizeof(char*));
      offset += 3;
      types_length = types_lengthT;
      for( uint8_t i = 0; i < types_length; i++){
      uint32_t length_st_types;
      memcpy(&length_st_types, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_types; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_types-1]=0;
      this->st_types = (char *)(inbuffer + offset-1);
      offset += length_st_types;
        memcpy( &(this->types[i]), &(this->st_types), sizeof(char*));
      }
      uint8_t typedefs_full_text_lengthT = *(inbuffer + offset++);
      if(typedefs_full_text_lengthT > typedefs_full_text_length)
        this->typedefs_full_text = (char**)realloc(this->typedefs_full_text, typedefs_full_text_lengthT * sizeof(char*));
      offset += 3;
      typedefs_full_text_length = typedefs_full_text_lengthT;
      for( uint8_t i = 0; i < typedefs_full_text_length; i++){
      uint32_t length_st_typedefs_full_text;
      memcpy(&length_st_typedefs_full_text, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_typedefs_full_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_typedefs_full_text-1]=0;
      this->st_typedefs_full_text = (char *)(inbuffer + offset-1);
      offset += length_st_typedefs_full_text;
        memcpy( &(this->typedefs_full_text[i]), &(this->st_typedefs_full_text), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return TOPICSANDRAWTYPES; };
    const char * getMD5(){ return "e1432466c8f64316723276ba07c59d12"; };

  };

  class TopicsAndRawTypes {
    public:
    typedef TopicsAndRawTypesRequest Request;
    typedef TopicsAndRawTypesResponse Response;
  };

}
#endif
