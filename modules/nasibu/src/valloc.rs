use crate::bindings::{size_t, vfree2, vmalloc};
use core::alloc::{GlobalAlloc, Layout};
use core::ptr;
use core::arch::asm;

struct VAlloc;

#[global_allocator]
static GLOBAL: VAlloc = VAlloc;

unsafe impl GlobalAlloc for VAlloc {
    unsafe fn alloc(&self, layout: Layout) -> *mut u8 {
        if let Ok(checked_size) = layout.size().try_into() {
            vmalloc(checked_size).cast()
        } else {
            ptr::null_mut()
        }
    }

    unsafe fn dealloc(&self, ptr: *mut u8, layout: Layout) {
        vfree2(ptr.cast(), layout.size() as size_t)
    }
}

#[alloc_error_handler]
fn foo(_: core::alloc::Layout) -> ! {
    loop {
        unsafe { asm!("hlt") }
    }
}
