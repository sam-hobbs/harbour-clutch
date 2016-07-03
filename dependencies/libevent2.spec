# Spec file for libevent2
# https://build.opensuse.org/package/view_file/home:aevseev/libevent2/libevent2.spec?expand=1

%define debug_packages %{nil}
%define debug_package %{nil}

Summary: Abstract asynchronous event notification library
Name: libevent
Version: 2.0.22
Release: 0
License: BSD
Group: System/Libraries
URL: http://libevent.org/

Source: https://github.com/downloads/libevent/libevent/libevent-%{version}-stable.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-root

BuildRequires: gcc-c++

%description
The libevent API provides a mechanism to execute a callback function
when a specific event occurs on a file descriptor or after a timeout
has been reached. libevent is meant to replace the asynchronous event
loop found in event driven network servers. An application just needs
to call event_dispatch() and can then add or remove events dynamically
without having to change the event loop.

%package devel
Summary: Header files, libraries and development documentation for %{name}
Group: Development/Libraries
Requires: %{name} = %{version}-%{release}

%description devel
This package contains the header files, static libraries and development
documentation for %{name}. If you like to develop programs using %{name},
you will need to install %{name}-devel.


%prep
%setup -n libevent-%{version}-stable

%build
./configure --disable-static --prefix=/usr
make

%install
rm -rf %{buildroot}
make install DESTDIR=%{buildroot}
rm -rf /usr/src/debug/*

%clean
[ "%{buildroot}" != "/" ] && rm -rf %{buildroot}

## files for libevent
%files
%defattr(-,root,root)
%doc LICENSE README
%{_libdir}/libevent*.so.*


## files for libevent-devel
%files devel
%defattr(-,root,root)
%{_bindir}/event_rpcgen.py
%{_libdir}/pkgconfig/*.pc
%{_includedir}/*.h
%{_includedir}/event2/
%{_libdir}/libevent*.so
%exclude %{_libdir}/libevent*.la

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%changelog
