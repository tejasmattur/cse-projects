import HomeSidebar from '../components/HomeSidebar';
import { getSession } from 'next-auth/react';
import { useState, useEffect } from 'react';
import { useRouter } from 'next/router';
import HomeForm from '../components/HomeForm';

export default function HomePage(props) {
  const router = useRouter();
  //const { data: session, status } = useSession();
  //const loading = status === 'loading';
  const [sessionEmail, setSessionEmail] = useState(props.email);
  useEffect(() => {
    router.prefetch('/users');
    router.prefetch('/history');
  }, []);
  /*if (session && sessionEmail === 'null') {
    setSessionEmail(session.user.email);
  }
  if (loading) {
    console.log('loading');
  }*/
  if (sessionEmail != 'nulled') {
    return (
      <div class="h-screen w-screen bg-lockplus-opacGray">
        <div class="relative flex bg-gray-800 justify-start">
          <div>
            <HomeSidebar />
          </div>
          <div>
            <HomeForm userEmail={sessionEmail} />
          </div>
        </div>
      </div>
    );
  } else {
    return (
      <div className="h-screen w-screen bg-lockplus-opacGray text-white font-lockplus">
        LOCKED OUT. Please sign in or register your lock
      </div>
    );
  }
}

export async function getServerSideProps(context) {
  const session = await getSession(context);
  let param = 'nulled';
  if (session) {
    param = session.user.email;
  }
  return {
    props: {
      sessionEmail: param,
    },
  };
}
