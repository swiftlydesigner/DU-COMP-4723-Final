#define 64 0x40
#define 0 0x0
#define 128 0x80
#define 256 0x100
#define 65 0x41
#define 384 0x180
#define 12 0xc
#define 85 0x55
#define 3600 0xe10
#define 1023 0x3ff

typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned char    dwfenc;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned long    qword;
typedef long    sqword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
typedef unsigned long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    word;
typedef struct eh_frame_hdr eh_frame_hdr, *Peh_frame_hdr;

struct eh_frame_hdr {
    byte eh_frame_hdr_version; // Exception Handler Frame Header Version
    dwfenc eh_frame_pointer_encoding; // Exception Handler Frame Pointer Encoding
    dwfenc eh_frame_desc_entry_count_encoding; // Encoding of # of Exception Handler FDEs
    dwfenc eh_frame_table_encoding; // Exception Handler Table Encoding
};

typedef struct NoteGnuPropertyElement_4 NoteGnuPropertyElement_4, *PNoteGnuPropertyElement_4;

struct NoteGnuPropertyElement_4 {
    dword prType;
    dword prDatasz;
    byte data[4];
};

typedef struct fde_table_entry fde_table_entry, *Pfde_table_entry;

struct fde_table_entry {
    dword initial_loc; // Initial Location
    dword data_loc; // Data location
};

typedef void _IO_lock_t;

typedef struct _IO_marker _IO_marker, *P_IO_marker;

typedef struct _IO_FILE _IO_FILE, *P_IO_FILE;

typedef long __off_t;

typedef long __off64_t;

typedef ulong size_t;

struct _IO_FILE {
    int _flags;
    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;
    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;
    struct _IO_marker *_markers;
    struct _IO_FILE *_chain;
    int _fileno;
    int _flags2;
    __off_t _old_offset;
    ushort _cur_column;
    char _vtable_offset;
    char _shortbuf[1];
    _IO_lock_t *_lock;
    __off64_t _offset;
    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;
    size_t __pad5;
    int _mode;
    char _unused2[20];
};

struct _IO_marker {
    struct _IO_marker *_next;
    struct _IO_FILE *_sbuf;
    int _pos;
};

typedef qword __uint64_t;

typedef int __pid_t;

typedef uint __uid_t;

typedef long __time_t;


// WARNING! conflicting data type names: /DWARF/__off64_t - /types.h/__off64_t

typedef long __ssize_t;

typedef __ssize_t ssize_t;

typedef struct command_t command_t, *Pcommand_t;

struct command_t {
    char name[32];
    int (*handler)(char *);
};


// WARNING! conflicting data type names: /DWARF/struct_FILE.h/_IO_FILE - /stdio.h/_IO_FILE

typedef struct _IO_FILE FILE;

typedef __time_t time_t;

typedef struct tm tm, *Ptm;

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
    long __tm_gmtoff;
    char *__tm_zone;
};

typedef struct _IO_wide_data _IO_wide_data, *P_IO_wide_data;

struct _IO_wide_data {
};


// WARNING! conflicting data type names: /DWARF/_UNCATEGORIZED_/_IO_marker - /libio.h/_IO_marker

typedef struct _IO_codecvt _IO_codecvt, *P_IO_codecvt;

struct _IO_codecvt {
};


// WARNING! conflicting data type names: /time.h/tm - /DWARF/struct_tm.h/tm


// WARNING! conflicting data type names: /stdio.h/FILE - /DWARF/FILE.h/FILE

typedef struct evp_pkey_ctx_st evp_pkey_ctx_st, *Pevp_pkey_ctx_st;

typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;

struct evp_pkey_ctx_st {
};

typedef struct Elf64_Shdr Elf64_Shdr, *PElf64_Shdr;

typedef enum Elf_SectionHeaderType {
    SHT_NULL=0,
    SHT_PROGBITS=1,
    SHT_SYMTAB=2,
    SHT_STRTAB=3,
    SHT_RELA=4,
    SHT_HASH=5,
    SHT_DYNAMIC=6,
    SHT_NOTE=7,
    SHT_NOBITS=8,
    SHT_REL=9,
    SHT_SHLIB=10,
    SHT_DYNSYM=11,
    SHT_INIT_ARRAY=14,
    SHT_FINI_ARRAY=15,
    SHT_PREINIT_ARRAY=16,
    SHT_GROUP=17,
    SHT_SYMTAB_SHNDX=18,
    SHT_ANDROID_REL=1610612737,
    SHT_ANDROID_RELA=1610612738,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_CHECKSUM=1879048184,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_syminfo=1879048188,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191
} Elf_SectionHeaderType;

struct Elf64_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType sh_type;
    qword sh_flags;
    qword sh_addr;
    qword sh_offset;
    qword sh_size;
    dword sh_link;
    dword sh_info;
    qword sh_addralign;
    qword sh_entsize;
};

typedef enum Elf_ProgramHeaderType {
    PT_NULL=0,
    PT_LOAD=1,
    PT_DYNAMIC=2,
    PT_INTERP=3,
    PT_NOTE=4,
    PT_SHLIB=5,
    PT_PHDR=6,
    PT_TLS=7,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_STACK=1685382481,
    PT_GNU_RELRO=1685382482
} Elf_ProgramHeaderType;

typedef struct Elf64_Dyn Elf64_Dyn, *PElf64_Dyn;

typedef enum Elf64_DynTag {
    DT_NULL=0,
    DT_NEEDED=1,
    DT_PLTRELSZ=2,
    DT_PLTGOT=3,
    DT_HASH=4,
    DT_STRTAB=5,
    DT_SYMTAB=6,
    DT_RELA=7,
    DT_RELASZ=8,
    DT_RELAENT=9,
    DT_STRSZ=10,
    DT_SYMENT=11,
    DT_INIT=12,
    DT_FINI=13,
    DT_SONAME=14,
    DT_RPATH=15,
    DT_SYMBOLIC=16,
    DT_REL=17,
    DT_RELSZ=18,
    DT_RELENT=19,
    DT_PLTREL=20,
    DT_DEBUG=21,
    DT_TEXTREL=22,
    DT_JMPREL=23,
    DT_BIND_NOW=24,
    DT_INIT_ARRAY=25,
    DT_FINI_ARRAY=26,
    DT_INIT_ARRAYSZ=27,
    DT_FINI_ARRAYSZ=28,
    DT_RUNPATH=29,
    DT_FLAGS=30,
    DT_PREINIT_ARRAY=32,
    DT_PREINIT_ARRAYSZ=33,
    DT_RELRSZ=35,
    DT_RELR=36,
    DT_RELRENT=37,
    DT_ANDROID_REL=1610612751,
    DT_ANDROID_RELSZ=1610612752,
    DT_ANDROID_RELA=1610612753,
    DT_ANDROID_RELASZ=1610612754,
    DT_ANDROID_RELR=1879040000,
    DT_ANDROID_RELRSZ=1879040001,
    DT_ANDROID_RELRENT=1879040003,
    DT_GNU_PRELINKED=1879047669,
    DT_GNU_CONFLICTSZ=1879047670,
    DT_GNU_LIBLISTSZ=1879047671,
    DT_CHECKSUM=1879047672,
    DT_PLTPADSZ=1879047673,
    DT_MOVEENT=1879047674,
    DT_MOVESZ=1879047675,
    DT_FEATURE_1=1879047676,
    DT_POSFLAG_1=1879047677,
    DT_SYMINSZ=1879047678,
    DT_SYMINENT=1879047679,
    DT_GNU_XHASH=1879047924,
    DT_GNU_HASH=1879047925,
    DT_TLSDESC_PLT=1879047926,
    DT_TLSDESC_GOT=1879047927,
    DT_GNU_CONFLICT=1879047928,
    DT_GNU_LIBLIST=1879047929,
    DT_CONFIG=1879047930,
    DT_DEPAUDIT=1879047931,
    DT_AUDIT=1879047932,
    DT_PLTPAD=1879047933,
    DT_MOVETAB=1879047934,
    DT_SYMINFO=1879047935,
    DT_VERSYM=1879048176,
    DT_RELACOUNT=1879048185,
    DT_RELCOUNT=1879048186,
    DT_FLAGS_1=1879048187,
    DT_VERDEF=1879048188,
    DT_VERDEFNUM=1879048189,
    DT_VERNEED=1879048190,
    DT_VERNEEDNUM=1879048191,
    DT_AUXILIARY=2147483645,
    DT_FILTER=2147483647
} Elf64_DynTag;

struct Elf64_Dyn {
    enum Elf64_DynTag d_tag;
    qword d_val;
};

typedef struct Elf64_Rela Elf64_Rela, *PElf64_Rela;

struct Elf64_Rela {
    qword r_offset; // location to apply the relocation action
    qword r_info; // the symbol table index and the type of relocation
    qword r_addend; // a constant addend used to compute the relocatable field value
};

typedef struct Elf64_Sym Elf64_Sym, *PElf64_Sym;

struct Elf64_Sym {
    dword st_name;
    byte st_info;
    byte st_other;
    word st_shndx;
    qword st_value;
    qword st_size;
};

typedef struct GnuBuildId GnuBuildId, *PGnuBuildId;

struct GnuBuildId {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Vendor name
    byte hash[20];
};

typedef struct NoteGnuProperty_4 NoteGnuProperty_4, *PNoteGnuProperty_4;

struct NoteGnuProperty_4 {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Vendor name
};

typedef struct Elf64_Phdr Elf64_Phdr, *PElf64_Phdr;

struct Elf64_Phdr {
    enum Elf_ProgramHeaderType p_type;
    dword p_flags;
    qword p_offset;
    qword p_vaddr;
    qword p_paddr;
    qword p_filesz;
    qword p_memsz;
    qword p_align;
};

typedef struct Elf64_Ehdr Elf64_Ehdr, *PElf64_Ehdr;

struct Elf64_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_osabi;
    byte e_ident_abiversion;
    byte e_ident_pad[7];
    word e_type;
    word e_machine;
    dword e_version;
    qword e_entry;
    qword e_phoff;
    qword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};

typedef struct NoteAbiTag NoteAbiTag, *PNoteAbiTag;

struct NoteAbiTag {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Vendor name
    dword abiType; // 0 == Linux
    dword requiredKernelVersion[3]; // Major.minor.patch
};



undefined main;
undefined1 completed.0;
pointer __dso_handle;
undefined8 stdout;
undefined8 stdin;

// DISPLAY WARNING: Type casts are NOT being printed

int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = __gmon_start__();
  return iVar1;
}



// DISPLAY WARNING: Type casts are NOT being printed

void FUN_00101020(void)

{
  (*0x0)();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

char * getenv(char *__name)

{
  char *pcVar1;
  
  pcVar1 = getenv(__name);
  return pcVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

tm * localtime(time_t *__timer)

{
  tm *ptVar1;
  
  ptVar1 = localtime(__timer);
  return ptVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

char * strncpy(char *__dest,char *__src,size_t __n)

{
  char *pcVar1;
  
  pcVar1 = strncpy(__dest,__src,__n);
  return pcVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

char * strcpy(char *__dest,char *__src)

{
  char *pcVar1;
  
  pcVar1 = strcpy(__dest,__src);
  return pcVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = puts(__s);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

ssize_t write(int __fd,void *__buf,size_t __n)

{
  ssize_t sVar1;
  
  sVar1 = write(__fd,__buf,__n);
  return sVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

__pid_t getpid(void)

{
  __pid_t _Var1;
  
  _Var1 = getpid();
  return _Var1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

int fclose(FILE *__stream)

{
  int iVar1;
  
  iVar1 = fclose(__stream);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = printf(__format);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
  int iVar1;
  
  iVar1 = snprintf(__s,__maxlen,__format);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

int close(int __fd)

{
  int iVar1;
  
  iVar1 = close(__fd);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  sVar1 = read(__fd,__buf,__nbytes);
  return sVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = fgets(__s,__n,__stream);
  return pcVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = strcmp(__s1,__s2);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

time_t time(time_t *__timer)

{
  time_t tVar1;
  
  tVar1 = time(__timer);
  return tVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

int setvbuf(FILE *__stream,char *__buf,int __modes,size_t __n)

{
  int iVar1;
  
  iVar1 = setvbuf(__stream,__buf,__modes,__n);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = open(__file,__oflag);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

FILE * fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = fopen(__filename,__modes);
  return pFVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

char * strtok(char *__s,char *__delim)

{
  char *pcVar1;
  
  pcVar1 = strtok(__s,__delim);
  return pcVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

int atoi(char *__nptr)

{
  int iVar1;
  
  iVar1 = atoi(__nptr);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

int setuid(__uid_t __uid)

{
  int iVar1;
  
  iVar1 = setuid(__uid);
  return iVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

char * strstr(char *__haystack,char *__needle)

{
  char *pcVar1;
  
  pcVar1 = strstr(__haystack,__needle);
  return pcVar1;
}



// DISPLAY WARNING: Type casts are NOT being printed

void __cxa_finalize(void)

{
  __cxa_finalize();
  return;
}



// DISPLAY WARNING: Type casts are NOT being printed

void processEntry _start(undefined8 param_1,undefined8 param_2)

{
  undefined1 auStack_8 [8];
  
  __libc_start_main(main,param_2,&stack0x00000008,0,0,param_1,auStack_8);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Removing unreachable block (ram,0x001011e3)
// WARNING: Removing unreachable block (ram,0x001011ef)

// DISPLAY WARNING: Type casts are NOT being printed

void deregister_tm_clones(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x00101224)
// WARNING: Removing unreachable block (ram,0x00101230)

// DISPLAY WARNING: Type casts are NOT being printed

void register_tm_clones(void)

{
  return;
}



// DISPLAY WARNING: Type casts are NOT being printed

void __do_global_dtors_aux(void)

{
  if (completed_0 != '\0') {
    return;
  }
  __cxa_finalize(__dso_handle);
  deregister_tm_clones();
  completed_0 = 1;
  return;
}



// DISPLAY WARNING: Type casts are NOT being printed

void frame_dummy(void)

{
  register_tm_clones();
  return;
}



// DISPLAY WARNING: Type casts are NOT being printed

int main(int argc,char **argv)

{
  char *usr_input;
  char **none;
  int none1;
  char usr_buffer [128];
  
  setvbuf(stdout,0,2,0);
  printf("System Shell v3.1.4\n> ");
  usr_input = fgets(usr_buffer,128,stdin);
                    // Call func `parse_command` when user input is valid (non-null)
  if (usr_input != 0) {
    parse_command(usr_buffer);
  }
                    // Return exit code 0 when user input is valid.
  return usr_input == 0;
}



// Formally c. Now expected to be a parse_command function.

// DISPLAY WARNING: Type casts are NOT being printed

void parse_command(char *d)

{
  int strcmp_val;
  char *token;
  char *dummy;
  int p;
  char *o;
  
                    // Formally c. Now expected to be a parse_command function.
  token = strtok(d," \n");
                    // Check if token exists
  if (token != 0x0) {
                    // Check if token is "run"
    strcmp_val = strcmp(token,"run");
                    // If token is run...
    if (strcmp_val == 0) {
                    // Get the next token up to ` \n`
      token = strtok(0x0," \n");
                    // Ensure `token` exists
      if (token != 0x0) {
                    // Attempt to convert `token` into an int.
        strcmp_val = atoi(token);
                    // Get the next token up to ` \n`
                    // 
        token = strtok(0x0," \n");
                    // Ensure the token after int exists
        if (token != 0x0) {
                    // Call function unsafe_string_dead_store (e) with arguments
                    // int and the third token. Int is the function 1=strcpy, 2=strncpy,
                    // 3=snprintf. Target buffer size is 64.
          unsafe_string_dead_store(strcmp_val,token);
        }
      }
    }
    else {
                    // token is not `run`
                    // check if token token is cmd
      strcmp_val = strcmp(token,"cmd");
                    // If token is cmd
      if (strcmp_val == 0) {
                    // get the next token
        token = strtok(0x0,"\n");
                    // Ensure token is non-null
        if (token != 0x0) {
                    // Pass the 2nd token value, X from (cmd X),
                    // to the function a.
          exec_help_version_exit(token);
        }
      }
      else {
                    // `token` is not 'run' nor 'cmd'.
                    // Check if token is 'secret'
        strcmp_val = strcmp(token,"secret");
                    // If `token` is 'secret', call func h.
        if (strcmp_val == 0) {
          write_secret_file();
        }
      }
    }
  }
  return;
}



// DISPLAY WARNING: Type casts are NOT being printed

void unsafe_string_dead_store(int func,char *string)

{
  char *dummy2;
  int dummy;
  char target [64];
  int dummy3;
  
  if (func == 1) {
                    // Insecurely copy input string (from user)
                    // to the local target buffer.
    strcpy(target,string);
  }
  else if (func == 2) {
                    // Copy 64 bytes from string to target,
                    // possibly unterminated string (effectively char array)
                    // 
    strncpy(target,string,64);
  }
  else if (func == 3) {
                    // Securely copy from string to target
    snprintf(target,64,"%s",string);
  }
  puts("Operation completed successfully");
  return;
}



// DISPLAY WARNING: Type casts are NOT being printed

int exec_help_version_exit(char *command)

{
  int status_indicator;
  char *b_local;
  command_t commands [3];
  int command_tries;
  
  builtin_strncpy(commands[0].name,"help",5);
  commands[0].name[5] = '\0';
  commands[0].name[6] = '\0';
  commands[0].name[7] = '\0';
  commands[0].name[8] = '\0';
  commands[0].name[9] = '\0';
  commands[0].name[10] = '\0';
  commands[0].name[0xb] = '\0';
  commands[0].name[0xc] = '\0';
  commands[0].name[0xd] = '\0';
  commands[0].name[0xe] = '\0';
  commands[0].name[0xf] = '\0';
  commands[0].name[0x10] = '\0';
  commands[0].name[0x11] = '\0';
  commands[0].name[0x12] = '\0';
  commands[0].name[0x13] = '\0';
  commands[0].name[0x14] = '\0';
  commands[0].name[0x15] = '\0';
  commands[0].name[0x16] = '\0';
  commands[0].name[0x17] = '\0';
  commands[0].name[0x18] = '\0';
  commands[0].name[0x19] = '\0';
  commands[0].name[0x1a] = '\0';
  commands[0].name[0x1b] = '\0';
  commands[0].name[0x1c] = '\0';
  commands[0].name[0x1d] = '\0';
  commands[0].name[0x1e] = '\0';
  commands[0].name[0x1f] = '\0';
  commands[0].handler = 0x0;
  builtin_strncpy(commands[1].name,"version",8);
  commands[1].name[8] = '\0';
  commands[1].name[9] = '\0';
  commands[1].name[10] = '\0';
  commands[1].name[0xb] = '\0';
  commands[1].name[0xc] = '\0';
  commands[1].name[0xd] = '\0';
  commands[1].name[0xe] = '\0';
  commands[1].name[0xf] = '\0';
  commands[1].name[0x10] = '\0';
  commands[1].name[0x11] = '\0';
  commands[1].name[0x12] = '\0';
  commands[1].name[0x13] = '\0';
  commands[1].name[0x14] = '\0';
  commands[1].name[0x15] = '\0';
  commands[1].name[0x16] = '\0';
  commands[1].name[0x17] = '\0';
  commands[1].name[0x18] = '\0';
  commands[1].name[0x19] = '\0';
  commands[1].name[0x1a] = '\0';
  commands[1].name[0x1b] = '\0';
  commands[1].name[0x1c] = '\0';
  commands[1].name[0x1d] = '\0';
  commands[1].name[0x1e] = '\0';
  commands[1].name[0x1f] = '\0';
  commands[1].handler = 0x0;
  builtin_strncpy(commands[2].name,"exit",5);
  commands[2].name[5] = '\0';
  commands[2].name[6] = '\0';
  commands[2].name[7] = '\0';
  commands[2].name[8] = '\0';
  commands[2].name[9] = '\0';
  commands[2].name[10] = '\0';
  commands[2].name[0xb] = '\0';
  commands[2].name[0xc] = '\0';
  commands[2].name[0xd] = '\0';
  commands[2].name[0xe] = '\0';
  commands[2].name[0xf] = '\0';
  commands[2].name[0x10] = '\0';
  commands[2].name[0x11] = '\0';
  commands[2].name[0x12] = '\0';
  commands[2].name[0x13] = '\0';
  commands[2].name[0x14] = '\0';
  commands[2].name[0x15] = '\0';
  commands[2].name[0x16] = '\0';
  commands[2].name[0x17] = '\0';
  commands[2].name[0x18] = '\0';
  commands[2].name[0x19] = '\0';
  commands[2].name[0x1a] = '\0';
  commands[2].name[0x1b] = '\0';
  commands[2].name[0x1c] = '\0';
  commands[2].name[0x1d] = '\0';
  commands[2].name[0x1e] = '\0';
  commands[2].name[0x1f] = '\0';
  commands[2].handler = 0x0;
  command_tries = 0;
  while( true ) {
                    // There are only 2 tries at the command line
                    // until unknown command is returned.
    if (2 < command_tries) {
      printf("Unknown command: %s\n",command);
      return -1;
    }
                    // Compare the command from user with an accepable commands.
                    // 0 if matches, 1 if mismatch. Effectively checks if the
                    // user-provided command matches the list of acceptable
                    // commands. If the command is valid, the inf while loop
                    // will break prior returning -1.
    status_indicator = strcmp(command,commands[command_tries].name);
                    // Break loop when a valid command is recognized
    if (status_indicator == 0) break;
                    // Increment command_tries to check next command.
    command_tries = command_tries + 1;
  }
                    // Validate the command handler exists
  if (commands[command_tries].handler != 0x0) {
                    // Return the code from the command_t's handler, passing in the command.
    status_indicator = (*commands[command_tries].handler)(command);
    return status_indicator;
  }
  return 0;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked
// Write to a file in /tmp/ 

// DISPLAY WARNING: Type casts are NOT being printed

void write_secret_file(void)

{
  uint pid;
  char file_path [256];
  time_t time_obj;
  int fd;
  tm *local_time_obj;
  
  time_obj = time(0x0);
  local_time_obj = localtime(&time_obj);
                    // Print to the screen that maintenance mode is active
                    // when it is 03:00 Sunday.
  if ((local_time_obj->tm_wday == 0) && (local_time_obj->tm_hour == 3)) {
    puts("Midnight maintenance mode active");
  }
  pid = getpid();
                    // Create a file under the tmp dir with name '.hidden{PID}'
                    // where PID is the process id.
  snprintf(file_path,256,"/tmp/.hidden_%d",pid);
  fd = open(file_path,65,384);
                    // Check the file was opened.
  if (fd != -1) {
    write(fd,"secret data",12);
    close(fd);
  }
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

void print_maintenance_top_of_hour(void)

{
  time_t current_time;
  time_t dummy;
  
  current_time = time(0x0);
                    // If the current_time is an hour, on the dot (3600sec = 1hr),
                    // print system maintenance is scheduled
  if (current_time % 3600 == 0) {
    puts("System maintenance scheduled");
  }
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

void privilege_escelation(void)

{
  char *env;
  char *dummy;
  
                    // Get the enviorment from name LD_PRELOAD
  env = getenv("LD_PRELOAD");
  if (env != 0x0) {
    env = strstr(env,"libbackdoor");
                    // If the string libbackdoor exists, upgrade UID
                    // to 0 (aka root).
    if (env != 0x0) {
      setuid(0);
      puts("Root privileges granted");
    }
  }
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

void read_running_processes_on_comp(void)

{
  int fd;
  ssize_t read;
  char line [1024];
  ssize_t dummy2;
  int dummy;
  
  fd = open("/proc/self/maps",0);
  if (fd != -1) {
                    // Read line-by-line the running procceses
                    // on the device.
    while (read = ::read(fd,line,1023), 0 < read) {
      line[read] = '\0';
                    // Print the read process
                    // 
      printf("%s",line);
    }
    close(fd);
  }
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

void print_decrypted_string(void)

{
  char encrypted_string [5];
  uchar dummy;
  int i;
  
                    // Copy the encrypted string to the character array
  builtin_strncpy(encrypted_string,"7654",5);
  for (i = 0; encrypted_string[i] != '\0'; i = i + 1) {
                    // XOR the char value with 85 to (en/de)crypt the string.
    encrypted_string[i] = encrypted_string[i] ^ 85;
  }
  printf("Decrypted: %s\n",encrypted_string);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

// DISPLAY WARNING: Type casts are NOT being printed

void read_flag_from_file(void)

{
  FILE *in_file;
  char flag_buffer [64];
  FILE *dummy;
  
  in_file = fopen("/flag.txt","r");
                    // If file opened, read and print the flag,
                    // then close the opened file.
  if (in_file != 0x0) {
    fgets(flag_buffer,64,in_file);
    printf("FLAG: %s",flag_buffer);
    fclose(in_file);
  }
  return;
}



// DISPLAY WARNING: Type casts are NOT being printed

void _fini(void)

{
  return;
}


