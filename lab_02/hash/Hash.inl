#include <memory>

// template <keyType Key, numType Type, 
//         typename Hash = hash<Key>, 
//         typename Pred = equal_to<Key>>
// void UnorderedMap<Key, Type, Hash, Pred>::BucketsAlloc(UnorderedMap<Key, Type, Hash, Pred>::size_type size)
// {
//     try
// 	{
// 		buckets = std::make_shared<Type>(size);
// 	}
// 	catch (std::bad_alloc &exception)
// 	{
// 		// throw MemoryError(__FILE__, typeid(*this).name(), __LINE__);
//         ;
// 	}
// }