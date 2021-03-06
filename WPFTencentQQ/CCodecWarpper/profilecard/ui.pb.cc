// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ui.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "ui.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace SummaryCardBusiEntry {

namespace {

const ::google::protobuf::Descriptor* ui_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ui_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_ui_2eproto() {
  protobuf_AddDesc_ui_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "ui.proto");
  GOOGLE_CHECK(file != NULL);
  ui_descriptor_ = file->message_type(0);
  static const int ui_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ui, url_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ui, title_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ui, content_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ui, jump_url_),
  };
  ui_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ui_descriptor_,
      ui::default_instance_,
      ui_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ui, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ui, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ui));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_ui_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ui_descriptor_, &ui::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_ui_2eproto() {
  delete ui::default_instance_;
  delete ui_reflection_;
}

void protobuf_AddDesc_ui_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\010ui.proto\022\024SummaryCardBusiEntry\"C\n\002ui\022\013"
    "\n\003url\030\001 \001(\t\022\r\n\005title\030\002 \001(\t\022\017\n\007content\030\003 "
    "\001(\t\022\020\n\010jump_url\030\004 \001(\t", 101);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "ui.proto", &protobuf_RegisterTypes);
  ui::default_instance_ = new ui();
  ui::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_ui_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_ui_2eproto {
  StaticDescriptorInitializer_ui_2eproto() {
    protobuf_AddDesc_ui_2eproto();
  }
} static_descriptor_initializer_ui_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ui::kUrlFieldNumber;
const int ui::kTitleFieldNumber;
const int ui::kContentFieldNumber;
const int ui::kJumpUrlFieldNumber;
#endif  // !_MSC_VER

ui::ui()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ui::InitAsDefaultInstance() {
}

ui::ui(const ui& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ui::SharedCtor() {
  _cached_size_ = 0;
  url_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  title_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  content_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  jump_url_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ui::~ui() {
  SharedDtor();
}

void ui::SharedDtor() {
  if (url_ != &::google::protobuf::internal::kEmptyString) {
    delete url_;
  }
  if (title_ != &::google::protobuf::internal::kEmptyString) {
    delete title_;
  }
  if (content_ != &::google::protobuf::internal::kEmptyString) {
    delete content_;
  }
  if (jump_url_ != &::google::protobuf::internal::kEmptyString) {
    delete jump_url_;
  }
  if (this != default_instance_) {
  }
}

void ui::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ui::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ui_descriptor_;
}

const ui& ui::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_ui_2eproto();
  return *default_instance_;
}

ui* ui::default_instance_ = NULL;

ui* ui::New() const {
  return new ui;
}

void ui::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_url()) {
      if (url_ != &::google::protobuf::internal::kEmptyString) {
        url_->clear();
      }
    }
    if (has_title()) {
      if (title_ != &::google::protobuf::internal::kEmptyString) {
        title_->clear();
      }
    }
    if (has_content()) {
      if (content_ != &::google::protobuf::internal::kEmptyString) {
        content_->clear();
      }
    }
    if (has_jump_url()) {
      if (jump_url_ != &::google::protobuf::internal::kEmptyString) {
        jump_url_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ui::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string url = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_url()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->url().data(), this->url().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_title;
        break;
      }

      // optional string title = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_title:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_title()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->title().data(), this->title().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_content;
        break;
      }

      // optional string content = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_content:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_content()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->content().data(), this->content().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_jump_url;
        break;
      }

      // optional string jump_url = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_jump_url:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_jump_url()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->jump_url().data(), this->jump_url().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void ui::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional string url = 1;
  if (has_url()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->url().data(), this->url().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->url(), output);
  }

  // optional string title = 2;
  if (has_title()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->title().data(), this->title().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->title(), output);
  }

  // optional string content = 3;
  if (has_content()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->content().data(), this->content().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->content(), output);
  }

  // optional string jump_url = 4;
  if (has_jump_url()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->jump_url().data(), this->jump_url().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->jump_url(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ui::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional string url = 1;
  if (has_url()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->url().data(), this->url().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->url(), target);
  }

  // optional string title = 2;
  if (has_title()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->title().data(), this->title().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->title(), target);
  }

  // optional string content = 3;
  if (has_content()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->content().data(), this->content().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->content(), target);
  }

  // optional string jump_url = 4;
  if (has_jump_url()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->jump_url().data(), this->jump_url().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->jump_url(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ui::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string url = 1;
    if (has_url()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->url());
    }

    // optional string title = 2;
    if (has_title()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->title());
    }

    // optional string content = 3;
    if (has_content()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->content());
    }

    // optional string jump_url = 4;
    if (has_jump_url()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->jump_url());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ui::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ui* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ui*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ui::MergeFrom(const ui& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_url()) {
      set_url(from.url());
    }
    if (from.has_title()) {
      set_title(from.title());
    }
    if (from.has_content()) {
      set_content(from.content());
    }
    if (from.has_jump_url()) {
      set_jump_url(from.jump_url());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ui::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ui::CopyFrom(const ui& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ui::IsInitialized() const {

  return true;
}

void ui::Swap(ui* other) {
  if (other != this) {
    std::swap(url_, other->url_);
    std::swap(title_, other->title_);
    std::swap(content_, other->content_);
    std::swap(jump_url_, other->jump_url_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ui::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ui_descriptor_;
  metadata.reflection = ui_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace SummaryCardBusiEntry

// @@protoc_insertion_point(global_scope)
