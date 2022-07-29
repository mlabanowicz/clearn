#ifndef DATA_TYPE_H__
#define DATA_TYPE_H__


#ifdef __cplusplus
extern"C" {
#endif

void datatype_info_char(char const *cptr);

void datatype_info_short(short const *hptr);

void datatype_info_int(int const *iptr);

void datatype_info_long(long const *lptr);

void datatype_info_str(char const *str);

void datatype_info_float(float const *fptr);

void datatype_info_double(double const *dptr);

#ifdef __cplusplus
}
#endif

#endif
