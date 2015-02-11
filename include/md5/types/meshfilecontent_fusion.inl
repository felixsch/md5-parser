#ifndef _MD5_MESHFILECONTENT_FUSION_H

#define _MD5_MESHFILECONTENT_FUSION_H
namespace boost {
namespace fusion {
namespace traits {
template< typename ivec2, typename fvec3 > struct tag_of<md5::meshfilecontent<ivec2, fvec3> > {
    typedef struct_tag type;
};
template< typename ivec2, typename fvec3 > struct tag_of<md5::meshfilecontent<ivec2, fvec3> const> {
    typedef struct_tag type;
};
} namespace extension {
template< typename ivec2, typename fvec3 > struct access::struct_member< md5::meshfilecontent<ivec2, fvec3> , 0 > {
    typedef int attribute_type;
    typedef attribute_type type;
    template<typename Seq> struct apply {
        typedef typename add_reference< typename mpl::eval_if< is_const<Seq> , add_const<attribute_type> , mpl::identity<attribute_type> >::type >::type type;
        static type call(Seq& seq) {
            return seq. version;
        }
    };
};
template< typename ivec2, typename fvec3 > struct struct_member_name< md5::meshfilecontent<ivec2, fvec3> , 0 > {
    typedef char const* type;
    static type call() {
        return "version";
    }
};
template< typename ivec2, typename fvec3 > struct access::struct_member< md5::meshfilecontent<ivec2, fvec3> , 1 > {
    typedef std::string attribute_type;
    typedef attribute_type type;
    template<typename Seq> struct apply {
        typedef typename add_reference< typename mpl::eval_if< is_const<Seq> , add_const<attribute_type> , mpl::identity<attribute_type> >::type >::type type;
        static type call(Seq& seq) {
            return seq. commandline;
        }
    };
};
template< typename ivec2, typename fvec3 > struct struct_member_name< md5::meshfilecontent<ivec2, fvec3> , 1 > {
    typedef char const* type;
    static type call() {
        return "commandline";
    }
};
template< typename ivec2, typename fvec3 > struct access::struct_member< md5::meshfilecontent<ivec2, fvec3> , 2 > {
    typedef int attribute_type;
    typedef attribute_type type;
    template<typename Seq> struct apply {
        typedef typename add_reference< typename mpl::eval_if< is_const<Seq> , add_const<attribute_type> , mpl::identity<attribute_type> >::type >::type type;
        static type call(Seq& seq) {
            return seq. num_joints;
        }
    };
};
template< typename ivec2, typename fvec3 > struct struct_member_name< md5::meshfilecontent<ivec2, fvec3> , 2 > {
    typedef char const* type;
    static type call() {
        return "num_joints";
    }
};
template< typename ivec2, typename fvec3 > struct access::struct_member< md5::meshfilecontent<ivec2, fvec3> , 3 > {
    typedef int attribute_type;
    typedef attribute_type type;
    template<typename Seq> struct apply {
        typedef typename add_reference< typename mpl::eval_if< is_const<Seq> , add_const<attribute_type> , mpl::identity<attribute_type> >::type >::type type;
        static type call(Seq& seq) {
            return seq. num_meshes;
        }
    };
};
template< typename ivec2, typename fvec3 > struct struct_member_name< md5::meshfilecontent<ivec2, fvec3> , 3 > {
    typedef char const* type;
    static type call() {
        return "num_meshes";
    }
};
template< typename ivec2, typename fvec3 > struct access::struct_member< md5::meshfilecontent<ivec2, fvec3> , 4 > {
    typedef std::vector< md5::joint< fvec3 > > attribute_type;
    typedef attribute_type type;
    template<typename Seq> struct apply {
        typedef typename add_reference< typename mpl::eval_if< is_const<Seq> , add_const<attribute_type> , mpl::identity<attribute_type> >::type >::type type;
        static type call(Seq& seq) {
            return seq. joints;
        }
    };
};
template< typename ivec2, typename fvec3 > struct struct_member_name< md5::meshfilecontent<ivec2, fvec3> , 4 > {
    typedef char const* type;
    static type call() {
        return "joints";
    }
};

template< typename ivec2, typename fvec3 > struct access::struct_member< md5::meshfilecontent<ivec2, fvec3> , 5 > {
    typedef std::vector< md5::mesh< ivec2, fvec3 > > attribute_type;
    typedef attribute_type type;
    template<typename Seq> struct apply {
        typedef typename add_reference< typename mpl::eval_if< is_const<Seq> , add_const<attribute_type> , mpl::identity<attribute_type> >::type >::type type;
        static type call(Seq& seq) {
            return seq. meshes;
        }
    };
};
template< typename ivec2, typename fvec3 > struct struct_member_name< md5::meshfilecontent<ivec2, fvec3> , 5 > {
    typedef char const* type;
    static type call() {
        return "meshes";
    }
};




template< typename ivec2, typename fvec3 > struct struct_size<md5::meshfilecontent<ivec2, fvec3> > : mpl::int_<6> {};
template< typename ivec2, typename fvec3 > struct struct_is_view< md5::meshfilecontent<ivec2, fvec3> > : mpl::false_ {};
}
} namespace mpl {
template<typename> struct sequence_tag;
template< typename ivec2, typename fvec3 > struct sequence_tag<md5::meshfilecontent<ivec2, fvec3> > {
    typedef fusion::fusion_sequence_tag type;
};
template< typename ivec2, typename fvec3 > struct sequence_tag< md5::meshfilecontent<ivec2, fvec3> const > {
    typedef fusion::fusion_sequence_tag type;
};
}
}








#endif /* end of include guard: _MD5_ */
