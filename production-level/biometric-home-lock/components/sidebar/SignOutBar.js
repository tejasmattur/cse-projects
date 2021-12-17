import { signOut } from 'next-auth/react';

function SignOutBar() {
  const url = `${process.env.FLUID_URL}/`;
  return (
    <button
      class="relative text-white flex items-center mt-48 space-x-2 px-4 ml-1 hover:text-lockplus-hoverGray"
      onClick={() => signOut({ callbackUrl: url })}>
      <span class="text-md font-light font-lockplus">sign out</span>
    </button>
  );
}

export default SignOutBar;
