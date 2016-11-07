// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: store.proto

#ifndef PROTOBUF_store_2eproto__INCLUDED
#define PROTOBUF_store_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace store {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_store_2eproto();
void protobuf_AssignDesc_store_2eproto();
void protobuf_ShutdownFile_store_2eproto();

class ProductInfo;
class ProductQuery;
class ProductReply;

// ===================================================================

class ProductQuery : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:store.ProductQuery) */ {
 public:
  ProductQuery();
  virtual ~ProductQuery();

  ProductQuery(const ProductQuery& from);

  inline ProductQuery& operator=(const ProductQuery& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ProductQuery& default_instance();

  void Swap(ProductQuery* other);

  // implements Message ----------------------------------------------

  inline ProductQuery* New() const { return New(NULL); }

  ProductQuery* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ProductQuery& from);
  void MergeFrom(const ProductQuery& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ProductQuery* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string product_name = 1;
  void clear_product_name();
  static const int kProductNameFieldNumber = 1;
  const ::std::string& product_name() const;
  void set_product_name(const ::std::string& value);
  void set_product_name(const char* value);
  void set_product_name(const char* value, size_t size);
  ::std::string* mutable_product_name();
  ::std::string* release_product_name();
  void set_allocated_product_name(::std::string* product_name);

  // @@protoc_insertion_point(class_scope:store.ProductQuery)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr product_name_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_store_2eproto();
  friend void protobuf_AssignDesc_store_2eproto();
  friend void protobuf_ShutdownFile_store_2eproto();

  void InitAsDefaultInstance();
  static ProductQuery* default_instance_;
};
// -------------------------------------------------------------------

class ProductReply : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:store.ProductReply) */ {
 public:
  ProductReply();
  virtual ~ProductReply();

  ProductReply(const ProductReply& from);

  inline ProductReply& operator=(const ProductReply& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ProductReply& default_instance();

  void Swap(ProductReply* other);

  // implements Message ----------------------------------------------

  inline ProductReply* New() const { return New(NULL); }

  ProductReply* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ProductReply& from);
  void MergeFrom(const ProductReply& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ProductReply* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .store.ProductInfo products = 1;
  int products_size() const;
  void clear_products();
  static const int kProductsFieldNumber = 1;
  const ::store::ProductInfo& products(int index) const;
  ::store::ProductInfo* mutable_products(int index);
  ::store::ProductInfo* add_products();
  ::google::protobuf::RepeatedPtrField< ::store::ProductInfo >*
      mutable_products();
  const ::google::protobuf::RepeatedPtrField< ::store::ProductInfo >&
      products() const;

  // @@protoc_insertion_point(class_scope:store.ProductReply)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::RepeatedPtrField< ::store::ProductInfo > products_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_store_2eproto();
  friend void protobuf_AssignDesc_store_2eproto();
  friend void protobuf_ShutdownFile_store_2eproto();

  void InitAsDefaultInstance();
  static ProductReply* default_instance_;
};
// -------------------------------------------------------------------

class ProductInfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:store.ProductInfo) */ {
 public:
  ProductInfo();
  virtual ~ProductInfo();

  ProductInfo(const ProductInfo& from);

  inline ProductInfo& operator=(const ProductInfo& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ProductInfo& default_instance();

  void Swap(ProductInfo* other);

  // implements Message ----------------------------------------------

  inline ProductInfo* New() const { return New(NULL); }

  ProductInfo* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ProductInfo& from);
  void MergeFrom(const ProductInfo& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ProductInfo* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional double price = 1;
  void clear_price();
  static const int kPriceFieldNumber = 1;
  double price() const;
  void set_price(double value);

  // optional string vendor_id = 2;
  void clear_vendor_id();
  static const int kVendorIdFieldNumber = 2;
  const ::std::string& vendor_id() const;
  void set_vendor_id(const ::std::string& value);
  void set_vendor_id(const char* value);
  void set_vendor_id(const char* value, size_t size);
  ::std::string* mutable_vendor_id();
  ::std::string* release_vendor_id();
  void set_allocated_vendor_id(::std::string* vendor_id);

  // @@protoc_insertion_point(class_scope:store.ProductInfo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  double price_;
  ::google::protobuf::internal::ArenaStringPtr vendor_id_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_store_2eproto();
  friend void protobuf_AssignDesc_store_2eproto();
  friend void protobuf_ShutdownFile_store_2eproto();

  void InitAsDefaultInstance();
  static ProductInfo* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ProductQuery

// optional string product_name = 1;
inline void ProductQuery::clear_product_name() {
  product_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ProductQuery::product_name() const {
  // @@protoc_insertion_point(field_get:store.ProductQuery.product_name)
  return product_name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ProductQuery::set_product_name(const ::std::string& value) {
  
  product_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:store.ProductQuery.product_name)
}
inline void ProductQuery::set_product_name(const char* value) {
  
  product_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:store.ProductQuery.product_name)
}
inline void ProductQuery::set_product_name(const char* value, size_t size) {
  
  product_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:store.ProductQuery.product_name)
}
inline ::std::string* ProductQuery::mutable_product_name() {
  
  // @@protoc_insertion_point(field_mutable:store.ProductQuery.product_name)
  return product_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ProductQuery::release_product_name() {
  // @@protoc_insertion_point(field_release:store.ProductQuery.product_name)
  
  return product_name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ProductQuery::set_allocated_product_name(::std::string* product_name) {
  if (product_name != NULL) {
    
  } else {
    
  }
  product_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), product_name);
  // @@protoc_insertion_point(field_set_allocated:store.ProductQuery.product_name)
}

// -------------------------------------------------------------------

// ProductReply

// repeated .store.ProductInfo products = 1;
inline int ProductReply::products_size() const {
  return products_.size();
}
inline void ProductReply::clear_products() {
  products_.Clear();
}
inline const ::store::ProductInfo& ProductReply::products(int index) const {
  // @@protoc_insertion_point(field_get:store.ProductReply.products)
  return products_.Get(index);
}
inline ::store::ProductInfo* ProductReply::mutable_products(int index) {
  // @@protoc_insertion_point(field_mutable:store.ProductReply.products)
  return products_.Mutable(index);
}
inline ::store::ProductInfo* ProductReply::add_products() {
  // @@protoc_insertion_point(field_add:store.ProductReply.products)
  return products_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::store::ProductInfo >*
ProductReply::mutable_products() {
  // @@protoc_insertion_point(field_mutable_list:store.ProductReply.products)
  return &products_;
}
inline const ::google::protobuf::RepeatedPtrField< ::store::ProductInfo >&
ProductReply::products() const {
  // @@protoc_insertion_point(field_list:store.ProductReply.products)
  return products_;
}

// -------------------------------------------------------------------

// ProductInfo

// optional double price = 1;
inline void ProductInfo::clear_price() {
  price_ = 0;
}
inline double ProductInfo::price() const {
  // @@protoc_insertion_point(field_get:store.ProductInfo.price)
  return price_;
}
inline void ProductInfo::set_price(double value) {
  
  price_ = value;
  // @@protoc_insertion_point(field_set:store.ProductInfo.price)
}

// optional string vendor_id = 2;
inline void ProductInfo::clear_vendor_id() {
  vendor_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ProductInfo::vendor_id() const {
  // @@protoc_insertion_point(field_get:store.ProductInfo.vendor_id)
  return vendor_id_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ProductInfo::set_vendor_id(const ::std::string& value) {
  
  vendor_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:store.ProductInfo.vendor_id)
}
inline void ProductInfo::set_vendor_id(const char* value) {
  
  vendor_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:store.ProductInfo.vendor_id)
}
inline void ProductInfo::set_vendor_id(const char* value, size_t size) {
  
  vendor_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:store.ProductInfo.vendor_id)
}
inline ::std::string* ProductInfo::mutable_vendor_id() {
  
  // @@protoc_insertion_point(field_mutable:store.ProductInfo.vendor_id)
  return vendor_id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ProductInfo::release_vendor_id() {
  // @@protoc_insertion_point(field_release:store.ProductInfo.vendor_id)
  
  return vendor_id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ProductInfo::set_allocated_vendor_id(::std::string* vendor_id) {
  if (vendor_id != NULL) {
    
  } else {
    
  }
  vendor_id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), vendor_id);
  // @@protoc_insertion_point(field_set_allocated:store.ProductInfo.vendor_id)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace store

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_store_2eproto__INCLUDED
