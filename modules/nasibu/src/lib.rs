#![no_std]
#![feature(alloc_error_handler)]

use core::panic::PanicInfo;

#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}

#[no_mangle]
pub extern "C" fn nbu_allow_logo() -> bool {
    false
}

pub mod allocator;

/// cbindgen:ignore
#[allow(non_upper_case_globals)]
#[allow(non_camel_case_types)]
#[allow(non_snake_case)]
#[allow(unused)]
#[path = "../tilck.rs"]
mod bindings;
